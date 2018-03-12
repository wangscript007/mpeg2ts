//
// Created by microlab on 2/24/18.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

/// Project files
#include "TsPacketInfo.h"
#include "TsPacketTestData.h"
#include "TsParser.h"

TEST(TsParserConstants, CheckConstants)
{
    EXPECT_EQ(TS_PACKET_HEADER_SIZE, 4);
    EXPECT_EQ(TS_PACKET_SIZE, 188);
    EXPECT_EQ(TS_PACKET_SYNC_BYTE, 0x47);
    EXPECT_EQ(TS_PACKET_MAX_PAYLOAD_SIZE, 184);
    EXPECT_EQ(TS_PACKET_PID_PAT, 0);
    EXPECT_EQ(TS_PACKET_PID_NULL, 0x1fff);
    EXPECT_EQ(PCR_SIZE, 6);
    EXPECT_EQ(OPCR_SIZE, 6);
}

TEST(TsParserConstants, CheckSyncByte)
{
    TsParser parser;
    const uint8_t packet_data[TS_PACKET_SIZE] = { 0x47 };
    EXPECT_TRUE(parser.checkSyncByte(packet_data));
    EXPECT_TRUE(parser.checkSyncByte(packet_1));
    EXPECT_TRUE(parser.checkSyncByte(packet_2));
    EXPECT_TRUE(parser.checkSyncByte(packet_3));
}

TEST(TsParserTests, CheckParserInfo)
{
    TsParser parser;
    // TsHeader hdr = parser.parseTsHeader(packet_1);

    TsPacketInfo info;
    parser.parseTsPacketInfo(packet_1, info);
    // std::cout << info.toString();

    // std::cout << hdr.toString();
    EXPECT_EQ(0, info.pcr);
    EXPECT_EQ(0, info.opcr);
    EXPECT_EQ(47, info.payloadSize);
    EXPECT_EQ(141, info.payloadStartOffset);
    EXPECT_TRUE(info.hasAdaptationField);

    // TODO add more tests
}

TEST(TsParserTests, CheckPid)
{
    TsParser parser;
    // TsHeader hdr = parser.parseTsHeader(packet_1);

    TsPacketInfo info;
    parser.parseTsPacketInfo(packet_3, info);
    EXPECT_EQ(289, info.pid);
    parser.parseTsPacketInfo(packet_4, info);
    EXPECT_EQ(481, info.pid);
    // TODO add more tests...
}

TEST(TsParserTests, CheckParsePatTable)
{
    TsParser parser;
    // TsHeader hdr = parser.parseTsHeader(packet_1);

    PsiTable pat;
    TsPacketInfo info;
    parser.parseTsPacketInfo(pat_packet_1, info);
    uint8_t table_id;
    parser.collectTable(pat_packet_1, info, table_id);
    EXPECT_EQ(PSI_TABLE_ID_PAT, table_id);
    pat = parser.parsePatPacket();
    EXPECT_EQ(TS_PACKET_PID_PAT, info.pid);
    EXPECT_EQ(PSI_TABLE_ID_PAT, pat.table_id);
    //    EXPECT_EQ(598, pat.network_PID);
}

TEST(TsParserTests, CheckParsePatTable2)
{
    TsParser parser;
    PatTable pat;
    TsPacketInfo info;

    parser.parseTsPacketInfo(pat_packet_2, info);
    uint8_t table_id;
    parser.collectTable(pat_packet_2, info, table_id);
    EXPECT_EQ(PSI_TABLE_ID_PAT, table_id);
    pat = parser.parsePatPacket();
    EXPECT_EQ(TS_PACKET_PID_PAT, info.pid);
    EXPECT_EQ(PSI_TABLE_ID_PAT, pat.table_id);

    EXPECT_EQ(0x04d, pat.section_length);
    EXPECT_EQ(0x03fd, pat.transport_stream_id);
    EXPECT_EQ(1, pat.version_number);
    EXPECT_EQ(0, pat.section_number);
    EXPECT_EQ(0, pat.last_section_number);

    EXPECT_EQ(17, pat.programs.size());

    EXPECT_EQ(0, pat.programs[0].program_number);
    EXPECT_EQ(0x10, pat.programs[0].program_map_PID);

    EXPECT_EQ(0x143c, pat.programs[1].program_number);
    EXPECT_EQ(0x143c, pat.programs[1].program_map_PID);

    EXPECT_EQ(0x13ba, pat.programs[2].program_number);
    EXPECT_EQ(0x13ba, pat.programs[2].program_map_PID);

    EXPECT_EQ(0x13ce, pat.programs[3].program_number);
    EXPECT_EQ(0x13ce, pat.programs[3].program_map_PID);

    EXPECT_EQ(0x15a4, pat.programs[4].program_number);
    EXPECT_EQ(0x15a4, pat.programs[4].program_map_PID);

    EXPECT_EQ(0x4d8, pat.programs[5].program_number);
    EXPECT_EQ(0x4d8, pat.programs[5].program_map_PID);

    EXPECT_EQ(0x1608, pat.programs[6].program_number);
    EXPECT_EQ(0x1608, pat.programs[6].program_map_PID);

    EXPECT_EQ(0x3f2, pat.programs[7].program_number);
    EXPECT_EQ(0x3f2, pat.programs[7].program_map_PID);

    EXPECT_EQ(0x16d0, pat.programs[8].program_number);
    EXPECT_EQ(0x16d0, pat.programs[8].program_map_PID);

    EXPECT_EQ(0x16a8, pat.programs[9].program_number);
    EXPECT_EQ(0x16a8, pat.programs[9].program_map_PID);

    EXPECT_EQ(0x50a, pat.programs[10].program_number);
    EXPECT_EQ(0x50a, pat.programs[10].program_map_PID);

    EXPECT_EQ(0x500, pat.programs[11].program_number);
    EXPECT_EQ(0x500, pat.programs[11].program_map_PID);

    EXPECT_EQ(0x366, pat.programs[12].program_number);
    EXPECT_EQ(0x366, pat.programs[12].program_map_PID);

    EXPECT_EQ(0xfffe, pat.programs[13].program_number);
    EXPECT_EQ(0x712, pat.programs[13].program_map_PID);

    EXPECT_EQ(0xbc2, pat.programs[14].program_number);
    EXPECT_EQ(0xbc2, pat.programs[14].program_map_PID);

    EXPECT_EQ(0xbcc, pat.programs[15].program_number);
    EXPECT_EQ(0xbcc, pat.programs[15].program_map_PID);

    EXPECT_EQ(0xbd6, pat.programs[16].program_number);
    EXPECT_EQ(0xbd6, pat.programs[16].program_map_PID);
}

TEST(TsParserTests, CheckParsePmtTable)
{
    TsParser parser;
    PmtTable pmt;
    TsPacketInfo info;

    parser.parseTsPacketInfo(pmt_packet_1, info);
    uint8_t table_id;
    parser.collectTable(pmt_packet_1, info, table_id);
    EXPECT_EQ(PSI_TABLE_ID_PMT, table_id);
    pmt = parser.parsePmtPacket();
    EXPECT_EQ(1010, info.pid);
    EXPECT_EQ(PSI_TABLE_ID_PMT, pmt.table_id);

    EXPECT_EQ(1, pmt.section_syntax_indicator);
    EXPECT_EQ(0x034, pmt.section_length);
    EXPECT_EQ(0x03f2, pmt.transport_stream_id);
    EXPECT_EQ((0xed >> 1) & 0x1F, pmt.version_number);
    EXPECT_EQ(1, pmt.current_next_indicator);
    EXPECT_EQ(0x00, pmt.section_number);
    EXPECT_EQ(0, pmt.last_section_number);

    // Extensions from PsiTable
    EXPECT_EQ(0x03fb, pmt.PCR_PID);
    EXPECT_EQ(0, pmt.program_info_length);

    EXPECT_EQ(4, pmt.streams.size());
    // ESPID=1004(0x3ec)
    EXPECT_EQ(0x6, pmt.streams[0].stream_type);
    EXPECT_EQ(0x3ec, pmt.streams[0].elementary_PID);
    EXPECT_EQ(7, pmt.streams[0].ES_info_length);

    // ESPID=1018(0x3fa)
    EXPECT_EQ(0x3, pmt.streams[1].stream_type);
    EXPECT_EQ(0x3fa, pmt.streams[1].elementary_PID);
    EXPECT_EQ(0, pmt.streams[1].ES_info_length);

    // ESPID=1017(0x3f9)
    EXPECT_EQ(0x6, pmt.streams[2].stream_type);
    EXPECT_EQ(0x3f9, pmt.streams[2].elementary_PID);
    EXPECT_EQ(12, pmt.streams[2].ES_info_length);

    // ESPID=1019(0x3fb)
    EXPECT_EQ(0x2, pmt.streams[3].stream_type);
    EXPECT_EQ(0x3fb, pmt.streams[3].elementary_PID);
    EXPECT_EQ(0, pmt.streams[3].ES_info_length);
}

TEST(TsParserTests, CheckParseTsHeader)
{
    TsParser parser;
    TsHeader hdr = parser.parseTsHeader(packet_3);

    EXPECT_EQ(289, hdr.PID);
    // parser.parseTsPacketInfo(packet_4, info);
    // EXPECT_EQ(481, info.pid);
    // TODO add more tests...
}

TEST(TsParserTests, CheckParselargePmtTable)
{
    TsParser parser;

    TsPacketInfo info;
    parser.parseTsPacketInfo(pmt_packet_2_1, info);
    uint8_t table_id;
    parser.collectTable(pmt_packet_2_1, info, table_id);
    EXPECT_EQ(PSI_TABLE_ID_INCOMPLETE, table_id);
    parser.parseTsPacketInfo(pmt_packet_2_2, info);
    parser.collectTable(pmt_packet_2_2, info, table_id);
    EXPECT_EQ(PSI_TABLE_ID_PMT, table_id);

    auto pmt = parser.parsePmtPacket();
    EXPECT_EQ(32, info.pid);
    EXPECT_EQ(PSI_TABLE_ID_PMT, pmt.table_id);

    // Extensions from PsiTable
    EXPECT_EQ(599, pmt.PCR_PID);
    EXPECT_EQ(22, pmt.program_info_length);

    EXPECT_EQ(9, pmt.streams.size());

    EXPECT_EQ(21, pmt.streams[8].stream_type);
    EXPECT_EQ(144, pmt.streams[8].elementary_PID);
    EXPECT_EQ(26, pmt.streams[8].ES_info_length);
}

TEST(MathTest, TwoPlusTwoEqualsFour)
{
    EXPECT_EQ(2 + 2, 4);
}


TEST(TsParserTests, TestParsePesPacket)
{
    TsParser parser;
    PesPacket pes;
    TsPacketInfo info;

    parser.parseTsPacketInfo(pes_packet_1, info);
    EXPECT_EQ(481, info.pid);

    EXPECT_TRUE(parser.collectPes(pes_packet_1, info));
    pes = parser.getPesPacket();
    EXPECT_EQ(PES_PACKET_START_CODE_PREFIX, pes.packet_start_code_prefix);
    EXPECT_EQ(STREAM_ID_pes_video_stream, pes.stream_id);
    EXPECT_EQ(0, pes.PES_packet_length); // Unbounded video packet.
    EXPECT_FALSE(pes.PES_scrambling_control); // Unscrambled.
    EXPECT_FALSE(pes.PES_priority);
    EXPECT_TRUE(pes.data_alignment_indicator);
    EXPECT_FALSE(pes.copyright);
    EXPECT_FALSE(pes.original_or_copy);
    EXPECT_EQ(3, pes.PTS_DTS_flags);
    EXPECT_FALSE(pes.ESCR_flag);

    EXPECT_FALSE(pes.ES_rate_flag);
    EXPECT_FALSE(pes.DSM_trick_mode_flag);
    EXPECT_FALSE(pes.additional_copy_info_flag);
    EXPECT_FALSE(pes.PES_CRC_flag);
    EXPECT_FALSE(pes.PES_extension_flag);
    EXPECT_EQ(10, pes.PES_header_data_length);
    EXPECT_EQ(689094304, pes.pts);
    EXPECT_EQ(689090704, pes.dts);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
