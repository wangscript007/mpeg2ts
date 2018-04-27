/**
 * Strictly Confidential - Do not duplicate or distribute without written
 * permission from authors
 */
#include <iostream>

// Project files
#include "CommonTypes.h"
#include "TsParser.h"


void TsParser::parseTsPacketInfo(const uint8_t* packet, TsPacketInfo& outInfo)
{
    TsPacketInfo zero = { 0 };
    outInfo = zero;

    TsHeader hdr = parseTsHeader(packet);
    outInfo.pid = hdr.PID;
    outInfo.errorIndicator = hdr.transport_error_indicator;
    outInfo.isPayloadStart = hdr.payload_unit_start_indicator;
    outInfo.hasAdaptationField = checkHasAdaptationField(hdr);
    outInfo.hasPayload = checkHasPayload(hdr);
    outInfo.continuityCounter = hdr.continuity_counter;

    if (outInfo.hasAdaptationField)
    {
        parseAdaptationFieldData(packet, outInfo);

        if (outInfo.privateDataSize > 0)
        {
            outInfo.hasPrivateData = true;
        }
        else
        {
            outInfo.hasPrivateData = false;
        }
    }
    if (outInfo.hasPayload)
    {
        outInfo.payloadSize = TS_PACKET_SIZE - getByteInx();
        outInfo.payloadStartOffset = getByteInx();
    }
}


bool TsParser::checkSyncByte(const uint8_t* byte)
{
    return TS_PACKET_SYNC_BYTE == byte[0];
}


TsHeader TsParser::parseTsHeader(const uint8_t* packet)
{
    TsHeader hdr;
    resetBits(packet, TS_PACKET_SIZE);

    hdr.sync_byte = getBits(8);
    hdr.transport_error_indicator = getBits(1);
    hdr.payload_unit_start_indicator = getBits(1);
    hdr.transport_priority = getBits(1);
    hdr.PID = getBits(13);
    hdr.transport_scrambling_control = getBits(2);
    hdr.adaptation_field_control = getBits(2);
    hdr.continuity_counter = getBits(4);
    return hdr;
}


bool TsParser::checkHasAdaptationField(TsHeader hdr)
{
    return (hdr.adaptation_field_control == TS_ADAPTATION_FIELD_CONTROL_ADAPTATION_ONLY ||
            hdr.adaptation_field_control == TS_ADAPTATION_FIELD_CONTROL_ADAPTATION_PAYLOAD);
}


bool TsParser::checkHasPayload(TsHeader hdr)
{
    return (hdr.adaptation_field_control == TS_ADAPTATION_FIELD_CONTROL_PAYLOAD_ONLY ||
            hdr.adaptation_field_control == TS_ADAPTATION_FIELD_CONTROL_ADAPTATION_PAYLOAD);
}


TsAdaptationFieldHeader TsParser::parseAdaptationFieldHeader()
{
    TsAdaptationFieldHeader hdr;
    hdr.adaptation_field_length = getBits(8);
    if (hdr.adaptation_field_length == 0)
    {
        return hdr;
    }
    hdr.discontinuity_indicator = getBits(1);
    hdr.random_access_indicator = getBits(1);
    hdr.elementary_stream_priority_indicator = getBits(1);
    hdr.PCR_flag = getBits(1);
    hdr.OPCR_flag = getBits(1);
    hdr.splicing_point_flag = getBits(1);
    hdr.transport_private_data_flag = getBits(1);
    hdr.adaptation_field_extension_flag = getBits(1);

    return hdr;
}


// Following spec Table 2-6 Transport stream adaptation field, see ISO/IEC 13818-1:2015.
void TsParser::parseAdaptationFieldData(const uint8_t* packet, TsPacketInfo& outInfo)
{
    TsAdaptationFieldHeader adaptHdr = parseAdaptationFieldHeader();
    // printf("AF len: %d\n", adaptHdr.adaptation_field_length);
    outInfo.pcr = -1;
    outInfo.opcr = -1;
    if (adaptHdr.adaptation_field_length == 0)
    {
        return;
    }

    auto ofsAfterAF =
    getByteInx() - 1 + adaptHdr.adaptation_field_length; //-1 8 flags in TsAdaptationFieldHeader

    if (adaptHdr.PCR_flag)
    {
        outInfo.pcr = parsePcr();
    }
    if (adaptHdr.OPCR_flag)
    {
        outInfo.opcr = parsePcr();
    }
    if (adaptHdr.splicing_point_flag)
    {
        /*outData.splice_countdown = */ getBits(8);
    }

    if (adaptHdr.transport_private_data_flag)
    {
        outInfo.privateDataSize = getBits(8);
        outInfo.privateDataOffset = getByteInx();
        for (uint32_t i = 0; i < outInfo.privateDataSize; i++) // skip it for now
        {
            getBits(8);
        }
    }

    if (adaptHdr.adaptation_field_extension_flag)
    {
        uint8_t adaptation_field_extension_length = getBits(8);
        for (uint8_t i = 0; i < adaptation_field_extension_length; i++) // skip it for now
        {
            getBits(8);
        }
    }
    outInfo.isDiscontinuity = adaptHdr.discontinuity_indicator;

    // 0..N stuffing bytes goes here and we have to adjust read offset
    resetBits(packet, TS_PACKET_SIZE, ofsAfterAF);
}


uint64_t TsParser::parsePcr()
{
    uint64_t pcr_base = 0;
    uint64_t pcr_extension = 0;

    pcr_base = getBits(33);
    getBits(6); // reserved

    pcr_extension = getBits(9);
    pcr_base = pcr_base * 300;
    pcr_base += pcr_extension;

    return pcr_base;
}


void TsParser::collectTable(const uint8_t* tsPacket, const TsPacketInfo& tsPacketInfo, uint8_t& table_id)
{
    uint8_t pointerOffset = tsPacketInfo.payloadStartOffset;

    checkCCError(tsPacketInfo.pid, tsPacketInfo.continuityCounter);
    checkTsDiscontinuity(tsPacketInfo.pid, tsPacketInfo.hasAdaptationField && tsPacketInfo.isDiscontinuity);

    if (tsPacketInfo.isPayloadStart)
    {
        mSectionBuffer.clear();

        const uint8_t pointer_field = tsPacket[pointerOffset];
        pointerOffset += sizeof(pointer_field);
        pointerOffset += pointer_field;
    }

    mSectionBuffer.insert(mSectionBuffer.end(), &tsPacket[pointerOffset], &tsPacket[TS_PACKET_SIZE]);
    PsiTable tableInfo;
    parsePsiTable(mSectionBuffer, tableInfo);
    table_id = (mSectionBuffer.size() < tableInfo.section_length) ? PSI_TABLE_ID_INCOMPLETE :
                                                                    tableInfo.table_id;
}


bool TsParser::collectPes(const uint8_t* tsPacket, const TsPacketInfo& tsPacketInfo, PesPacket& pesPacket)
{
    bool ret = false;
    uint8_t pointerOffset = tsPacketInfo.payloadStartOffset;
    auto pid = tsPacketInfo.pid;

    checkCCError(pid, tsPacketInfo.continuityCounter);
    checkTsDiscontinuity(pid, tsPacketInfo.hasAdaptationField && tsPacketInfo.isDiscontinuity);
    if (tsPacketInfo.hasAdaptationField)
    {
        buildPcrHistogram(pid, tsPacketInfo.pcr);
    }

    if (tsPacketInfo.isPayloadStart)
    {
        // We have start. So if we have any cached data it's time to return it.
        if (!mPesPacket[pid].mPesBuffer.empty())
        {
            if (mPesPacket[pid].PES_packet_length &&
                mPesPacket[pid].mPesBuffer.size() < mPesPacket[pid].PES_packet_length)
            {
                std::cerr << "Not returning incomplete PES packet on pid " << pid << "\n";
            }
            else
            {
                pesPacket = mPesPacket[pid]; // TODO: must copy as we override it below.

                buildPtsHistogram(pid, pesPacket.pts);
                buildDtsHistogram(pid, pesPacket.dts);

                ret = true;
            }
        }

        // Create new PES
        mPesPacket[pid] = PesPacket();
        pid = tsPacketInfo.pid;

        mPesPacket[pid].mPesBuffer.insert(mPesPacket[pid].mPesBuffer.end(),
                                          &tsPacket[pointerOffset], &tsPacket[TS_PACKET_SIZE]);

        parsePesPacket(pid);
    }
    else
    {
        if (mPesPacket.count(pid) == 0)
        {
            // PES has not started yet. Ignoring rest
            return false;
        }

        // Assemble packet
        mPesPacket[pid].mPesBuffer.insert(mPesPacket[pid].mPesBuffer.end(),
                                          &tsPacket[pointerOffset], &tsPacket[TS_PACKET_SIZE]);
        // TODO: check if we have boud PES and return it if it is coplete
    }

    return ret;
}

void TsParser::parsePsiTable(const ByteVector& table, PsiTable& tableInfo)
{
    resetBits(table.data(), TS_PACKET_SIZE, 0);

    tableInfo.table_id = getBits(8);
    tableInfo.section_syntax_indicator = getBits(1);
    getBits(1); // '0'
    getBits(2); // reserved
    tableInfo.section_length = getBits(12);
    tableInfo.transport_stream_id = getBits(16);
    getBits(2);
    tableInfo.version_number = getBits(5);
    tableInfo.current_next_indicator = getBits(1);
    tableInfo.section_number = getBits(8);
    tableInfo.last_section_number = getBits(8);
}


PatTable TsParser::parsePatPacket()
{
    PatTable pat;
    parsePsiTable(mSectionBuffer, pat);

    int numberOfPrograms = (pat.section_length - PAT_PACKET_OFFSET_LENGTH - CRC32_SIZE) / PAT_PACKET_PROGRAM_SIZE;

    for (int i = 0; i < numberOfPrograms; i++)
    {
        Program prg;
        prg.program_number = getBits(16);
        getBits(3); // reserved
        prg.program_map_PID = getBits(13);
        pat.programs.push_back(prg);
    }

    return pat;
}


PmtTable TsParser::parsePmtPacket()
{
    PmtTable pmt;
    parsePsiTable(mSectionBuffer, pmt);

    getBits(3); // reserved
    pmt.PCR_PID = getBits(13);
    getBits(4); // reserved
    pmt.program_info_length = getBits(12);
    getBits(8 * pmt.program_info_length); // skip descriptors for now

    int streamsSize = (pmt.section_length - PMT_PACKET_OFFSET_LENGTH - CRC32_SIZE - pmt.program_info_length);

    int readSize = 0;
    while (readSize < streamsSize)
    {
        StreamTypeHeader hdr;
        hdr.stream_type = getBits(8);
        getBits(3); // reserved
        hdr.elementary_PID = getBits(13);
        getBits(4); // reserved
        hdr.ES_info_length = getBits(12);
        getBits(hdr.ES_info_length * 8); // Skip for now
        readSize += hdr.ES_info_length + PMT_STREAM_TYPE_LENGTH;
        pmt.streams.push_back(hdr);
    }

    return pmt;
}


void TsParser::parsePesPacket(int16_t pid)
{
    resetBits(mPesPacket[pid].mPesBuffer.data(), TS_PACKET_SIZE, 0);

    mPesPacket[pid].packet_start_code_prefix = getBits(24);
    mPesPacket[pid].stream_id = getBits(8);
    mPesPacket[pid].PES_packet_length = getBits(16);
    mPesPacket[pid].elementary_data_offset = 0;

    // ISO/IEC 13818-1:2015: Table 2-21 PES packet
    if (mPesPacket[pid].stream_id != STREAM_ID_program_stream_map &&
        mPesPacket[pid].stream_id != STREAM_ID_padding_stream && mPesPacket[pid].stream_id != STREAM_ID_private_stream_2 &&
        mPesPacket[pid].stream_id != STREAM_ID_ECM_stream && mPesPacket[pid].stream_id != STREAM_ID_EMM_stream &&
        mPesPacket[pid].stream_id != STREAM_ID_program_stream_directory &&
        mPesPacket[pid].stream_id != STREAM_ID_DSMCC_stream &&
        mPesPacket[pid].stream_id != STREAM_ID_ITU_T_Rec_H222_1_type_E_stream)
    {
        getBits(2); // '10'
        mPesPacket[pid].PES_scrambling_control = getBits(2);

        mPesPacket[pid].PES_priority = getBits(1);
        mPesPacket[pid].data_alignment_indicator = getBits(1);
        mPesPacket[pid].copyright = getBits(1);
        mPesPacket[pid].original_or_copy = getBits(1);
        mPesPacket[pid].PTS_DTS_flags = getBits(2);
        mPesPacket[pid].ESCR_flag = getBits(1);
        mPesPacket[pid].ES_rate_flag = getBits(1);
        mPesPacket[pid].DSM_trick_mode_flag = getBits(1);
        mPesPacket[pid].additional_copy_info_flag = getBits(1);
        mPesPacket[pid].PES_CRC_flag = getBits(1);
        mPesPacket[pid].PES_extension_flag = getBits(1);

        mPesPacket[pid].PES_header_data_length = getBits(8);
        mPesPacket[pid].elementary_data_offset = mPesPacket[pid].PES_header_data_length + getByteInx();

        mPesPacket[pid].pts = -1;
        mPesPacket[pid].dts = -1;
        // Forbidden value
        if (mPesPacket[pid].PTS_DTS_flags == 0x01)
        {
            std::cout << "Forbidden PTS_DTS_flags:" << mPesPacket[pid].PTS_DTS_flags << std::endl;
        }
        else if (mPesPacket[pid].PTS_DTS_flags == 0x02) // Only PTS value
        {
            getBits(4);
            uint64_t pts = 0;
            uint64_t pts_32_30 = getBits(3);
            getBits(1); // marker_bit
            uint64_t pts_29_15 = getBits(15);
            getBits(1); // marker_bit
            uint64_t pts_14_0 = getBits(15);
            getBits(1); // marker_bit

            pts = (pts_32_30 << 30) + (pts_29_15 << 15) + pts_14_0;

            mPesPacket[pid].pts = pts;
            mPesPacket[pid].dts = -1;
        }
        else if (mPesPacket[pid].PTS_DTS_flags == 0x03) // Both PTS and DTS
        {
            getBits(4);
            uint64_t pts = 0;
            uint64_t pts_32_30 = getBits(3);
            getBits(1); // marker_bit
            uint64_t pts_29_15 = getBits(15);
            getBits(1); // marker_bit
            uint64_t pts_14_0 = getBits(15);
            getBits(1); // marker_bit

            pts = (pts_32_30 << 30) + (pts_29_15 << 15) + pts_14_0;

            mPesPacket[pid].pts = pts;

            getBits(4);
            uint64_t dts = 0;
            uint64_t dts_32_30 = getBits(3);
            getBits(1); // marker_bit
            uint64_t dts_29_15 = getBits(15);
            getBits(1); // marker_bit
            uint64_t dts_14_0 = getBits(15);
            getBits(1); // marker_bit

            dts = (dts_32_30 << 30) + (dts_29_15 << 15) + dts_14_0;

            mPesPacket[pid].dts = dts;
        }
    }
}
