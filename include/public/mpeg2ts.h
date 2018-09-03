/**
 * Strictly Confidential - Do not duplicate or distribute without written
 * permission from authors
 */

#pragma once
#ifdef _WIN32

#ifdef MPEG2TS_DLL_EXPORTS
#define MPEG2TS_API __declspec(dllexport)
#else
#define MPEG2TS_API __declspec(dllimport)
#endif

#elif __linux__
#define MPEG2TS_API
#endif


#include <functional>
#include <map>
#include <memory>
#include <vector>
#include <cstdint>

/// project files
#include <public/Ts_IEC13818-1.h> // For TsHeader  Program


namespace mpeg2ts
{
// Common types
typedef std::vector<uint8_t> ByteVector;
typedef std::shared_ptr<ByteVector> ByteVectorPtr;

// Internal types // TODO remove to internal h-file
/// Window types
#ifdef WIN32
#define ssize_t size_t
typedef char TCHAR;
#endif


// forward declarations
class TsParser;

/*!
 * @class PES-Packet prototype containing buffer
 *
 */
struct PesPacket
{
    uint32_t packet_start_code_prefix;
    uint8_t stream_id;
    uint16_t PES_packet_length;

    // Extended packet
    // TODO move out by inheritance?
    bool PES_scrambling_control;
    bool PES_priority;
    bool data_alignment_indicator;
    bool copyright;
    bool original_or_copy;
    uint8_t PTS_DTS_flags;
    bool ESCR_flag;
    bool ES_rate_flag;
    bool DSM_trick_mode_flag;
    bool additional_copy_info_flag;
    bool PES_CRC_flag;
    bool PES_extension_flag;

    uint8_t PES_header_data_length;
    uint16_t elementary_data_offset; // where ES data begins

    int64_t pts;
    int64_t dts;

    ByteVector mPesBuffer;

    friend std::ostream& operator<<(std::ostream& ss, const PesPacket& rhs);
};


/*!
 * @brief Base class for all PSI tables
 */
class PsiTable
{
public:
    PsiTable()
    {
        table_id = 0;
        section_syntax_indicator = false;
        section_length = 0;
        transport_stream_id = 0;
        version_number = 0;
        current_next_indicator = false;
        section_number = 0;
        last_section_number = 0;
        CRC_32 = 0;
    }

    virtual ~PsiTable() = default;

    uint8_t table_id;
    bool section_syntax_indicator;
    uint16_t section_length;
    uint16_t transport_stream_id; // TODO program_number for PMT? Use Union?
    uint8_t version_number;
    bool current_next_indicator;
    uint8_t section_number;
    uint8_t last_section_number;
    uint32_t CRC_32;

    friend std::ostream& operator<<(std::ostream& ss, const PsiTable& rhs);

    /// @brief Comparison operator for comparing 2 PsiTables
    bool operator==(const PsiTable& rhs) const;

    bool operator!=(const PsiTable& rhs) const;
};

/*!
 * PAT table
 */
class PatTable : public PsiTable
{
public:
    std::vector<Program> programs;

    friend std::ostream& operator<<(std::ostream& ss, const PatTable& rhs);

    /// @brief Comparison operator for comparing 2 PatTables
    bool operator==(const PatTable& rhs) const;

    bool operator!=(const PatTable& rhs) const;
};

struct StreamTypeHeader
{
    StreamType stream_type;
    uint16_t elementary_PID;
    uint16_t ES_info_length;

    friend std::ostream& operator<<(std::ostream& ss, const StreamTypeHeader& rhs);

    bool operator==(const StreamTypeHeader& rhs) const;

    bool operator!=(const StreamTypeHeader& rhs) const;
};

/*!
 * PMT Table.
 */
class PmtTable : public PsiTable
{
public:
    uint16_t PCR_PID;
    uint16_t program_info_length;
    //    std::vector<Descriptor> descriptors; // TODO
    std::vector<StreamTypeHeader> streams;


    friend std::ostream& operator<<(std::ostream& ss, const PmtTable& rhs);

    /// @brief Comparison operator for comparing 2 PmtTables
    bool operator==(const PmtTable& rhs) const;

    bool operator!=(const PmtTable& rhs) const;
};

struct CatDescriptor
{
};

class CatTable : public PsiTable
{
public:
    std::vector<CatDescriptor> descriptors;
};


class TsPacketInfo
{
public:
    uint16_t pid; // This Packet Identifier.
    TsHeader hdr; // This packet Ts Header

    bool errorIndicator;     // If indication of at least 1 uncorrectable bit in ts-packet
    bool isPayloadStart;     // If this packet is the first in a PES-packet.
    bool hasAdaptationField; // If this packet contains adaptation field data.
    bool hasPayload;         // If this packet contains payload.
    bool hasPrivateData;     // If this packet contains private data.
    bool hasRandomAccess;    // If this packet contain aid random access.
    bool isScrambled;        // If this packet is scrambled
    bool isDiscontinuity;    // If this packet has discontinuity flag set

    uint8_t continuityCounter : 4; // 4-bit continuity counter

    // Adaptation field data:
    uint64_t pcr; // PCR clock...
    uint64_t opcr;

    // For elementary-streams
    uint64_t pts;
    uint64_t dts;

    // Private data:
    uint32_t privateDataSize;
    uint32_t privateDataOffset;

    // Payload data:
    size_t payloadSize;         // The size of the payload
    uint8_t payloadStartOffset; // Offset from and sync byte to start of payload.

    bool isError; // If a parser error or TS not following standards.


    friend std::ostream& operator<<(std::ostream& ss, const TsPacketInfo& rhs);
};

// TODO check these
const int64_t CLOCK_90_KHZ = 90000;
const int64_t TIME_STAMP_JUMP_DISCONTINUITY_LEVEL = 3 * CLOCK_90_KHZ; // 3s


struct PidStatistic
{
    static const uint8_t INVALID_CC = 16;
    PidStatistic()
            : lastCC{ INVALID_CC }
            , numberOfCCErrors{ 0 }
            , numberOfTsDiscontinuities{ 0 }
            , lastPts{ -1 }
            , lastDts{ -1 }
            , lastPcr{ -1 }
            , numberOfMissingPts{ 0 }
            , numberOfMissingDts{ 0 }
    {
    }

    uint8_t lastCC;
    uint64_t numberOfCCErrors;

    uint64_t numberOfTsDiscontinuities;

    int64_t lastPts;
    std::map<int64_t, uint64_t> ptsHistogram;

    int64_t lastDts;
    std::map<int64_t, uint64_t> dtsHistogram;

    int64_t lastPcr;
    std::map<int64_t, uint64_t> pcrHistogram;

    uint64_t numberOfMissingPts;

    uint64_t numberOfMissingDts;
};



class TsStatistics
{
public:
    explicit TsStatistics();

    /*!
     * Calculates Continuity errors.
     * @param pid Filtered PID.
     * @param cc Current TS packets Continuity Counter.
     */
    void checkCCError(int pid, uint8_t cc);

    /*!
     * Book keep flagged TS packets discontinuities.
     * @param pid Filtered PID.
     * @param isDiscontinuous Whether or not this is a discontinuity.
     */
    void checkTsDiscontinuity(int pid, bool isDiscontinuous);

    /*!
     * Build a histogram of PTS differences between 2 time samples.
     * @param pid Filtered PID.
     * @param pts Program Time Stamp value.
     */
    void buildPtsHistogram(int pid, int64_t pts);

    /*!
     * Build a histogram of DTS differences between 2 time samples.
     * @param pid Filtered PID.
     * @param pts Display Time Stamp value.
     */
    void buildDtsHistogram(int pid, int64_t dts);

    /*!
     * Build a histogram of PCR differences between 2 time samples.
     * @param pid Filtered PID.
     * @param pts Program Clock Reference value.
     */
    void buildPcrHistogram(int pid, int64_t pcr);

    std::map<int, PidStatistic> mPidStatistics;
    uint64_t mTsPacketCounter;
    uint64_t mTsPacketNullPacketCounter;
    uint64_t mTsPacketErrorIndicator;
};






typedef std::function<void(PsiTable* table, uint16_t pid, void* hdl)> PsiCallBackFnc;
typedef std::function<void(const PesPacket& table, uint16_t pid, void* hdl)> PesCallBackFnc;
typedef std::function<void(const uint8_t* packet, TsPacketInfo tsPacketInfo, void* hdl)> TsCallBackFnc;

/// @brief Demux ts packets into PSI and PES (plus TS pass through)
class TsDemuxer
{
public:
    MPEG2TS_API explicit TsDemuxer();

    MPEG2TS_API ~TsDemuxer();

    /*!
     * Demuxes a transport stream packed based on its Packet ID.
     * @param tsPacket The TS packet to demux.
     */
    MPEG2TS_API void demux(const uint8_t* tsPacket);

    /*!
     * Outputs to callback function when found a PSI table with PID.
     * @param pid The PID to filter PSI tables.
     * @param cb Returns a complete PSI table to this callback function.
     * @param hdl Custom handler
     */
    MPEG2TS_API void addPsiPid(int pid, PsiCallBackFnc cb, void* hdl);

    /*!
     * Returns a complete PES packet with PID.
     * @param pid The PID to filter PES packets.
     * @param cb  Callback when found a complete PES packet.
     * @param hdl Custom handler
     */
    MPEG2TS_API void addPesPid(int pid, PesCallBackFnc cb, void* hdl);

    /*!
     * Returns a complete TS packet filtered on PID.
     * @param pid The PID to filter TS packets.
     * @param cb Callback when found a TS packet.
     * @param hdl Custom handler
     */
    MPEG2TS_API void addTsPid(int pid, TsCallBackFnc cb, void* hdl);

    /*!
     * Returns statistics on parsed transport stream packets.
     * @return TsStatistics containing collected statistics for all demuxed packets.
     */
    MPEG2TS_API TsStatistics

    getTsStatistics() const;

protected:
    std::map<int, PsiCallBackFnc> mPsiCallbackMap;
    std::map<int, PesCallBackFnc> mPesCallbackMap;
    std::map<int, TsCallBackFnc> mTsCallbackMap;
    std::map<int, void*> mHandlers;

private:
    // Make this object be non copyable because it holds a pointer
    TsDemuxer(const TsDemuxer&);

    const TsDemuxer& operator=(const TsDemuxer&);

    TsParser* mParser;
};

} // namespace mpeg2ts
