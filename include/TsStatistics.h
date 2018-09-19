#pragma once

#include <cstdint>
#include "public/mpeg2ts.h"

namespace mpeg2ts
{

class TsStatistics
{
public:
    // Constants
    const int64_t CLOCK_90_KHZ = 90000;
    const int64_t TIME_STAMP_JUMP_DISCONTINUITY_LEVEL = 3 * CLOCK_90_KHZ; // 3s

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

    PidStatisticsType mPidStatistics;
    uint64_t mTsPacketCounter;
    uint64_t mTsPacketNullPacketCounter;
    uint64_t mTsPacketErrorIndicator;
};


} // namespace mpeg2ts
