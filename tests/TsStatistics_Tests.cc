
#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

/// Project files CUT (Class Under Test)
#include "TsStatistics.h"

/// Project files
#include "TsPacketTestData.h"
#include "mpeg2ts.h"

using namespace mpeg2ts;


TEST(TsStatisticsTests, TestConstants)
{
    EXPECT_EQ(TsStatistics::CLOCK_90_KHZ, 90000);
    EXPECT_EQ(TsStatistics::TIME_STAMP_JUMP_DISCONTINUITY_LEVEL, 3 * 90000);
}

/*!
 * Test verify that we count number of discontinuous packets correctly.
 */
TEST(TsStatisticsTests, TestCCError)
{
    TsStatistics statistics;
    statistics.checkCCError(0, 0);
    statistics.checkCCError(0, 2);
    statistics.checkCCError(1, 0);
    statistics.checkCCError(1, 1);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfCCErrors, 1);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfCCErrors, 0);
    statistics.checkCCError(0, 4);
    statistics.checkCCError(1, 2);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfCCErrors, 2);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfCCErrors, 0);
    statistics.checkCCError(0, 5);
    statistics.checkCCError(1, 3);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfCCErrors, 2);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfCCErrors, 0);
    statistics.checkCCError(0, 6);
    statistics.checkCCError(1, 4);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfCCErrors, 2);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfCCErrors, 0);
}

/*!
 * Test that measured TS discontinuities are correct.
 */
TEST(TsStatisticsTests, TestTsDiscontinuities)
{
    TsStatistics statistics;
    statistics.checkTsDiscontinuity(0, false);
    statistics.checkTsDiscontinuity(1, false);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfTsDiscontinuities, 0);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfTsDiscontinuities, 0);
    statistics.checkTsDiscontinuity(0, true);
    statistics.checkTsDiscontinuity(1, false);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfTsDiscontinuities, 1);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfTsDiscontinuities, 0);
    statistics.checkTsDiscontinuity(0, true);
    statistics.checkTsDiscontinuity(1, false);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfTsDiscontinuities, 2);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfTsDiscontinuities, 0);
    statistics.checkTsDiscontinuity(0, false);
    statistics.checkTsDiscontinuity(1, true);
    EXPECT_EQ(statistics.getPidStatistics()[0].numberOfTsDiscontinuities, 2);
    EXPECT_EQ(statistics.getPidStatistics()[1].numberOfTsDiscontinuities, 1);
}

/*!
 * Test that we build a PTS histogram based on time differences.
 */
TEST(TsStatisticsTests, TestPtsHistogram)
{
    TsStatistics statistics;
    int64_t time_step = 1 * 90000; // 1s time step
    statistics.buildPtsHistogram(0, 0);
    statistics.buildPtsHistogram(0, time_step);
    statistics.buildPtsHistogram(0, 2 * time_step);
    statistics.buildPtsHistogram(1, 10 * time_step);

    EXPECT_EQ(statistics.getPidStatistics()[0].ptsHistogram[0], 0u);
    EXPECT_EQ(statistics.getPidStatistics()[0].ptsHistogram[time_step], 2u);
    EXPECT_EQ(statistics.getPidStatistics()[1].ptsHistogram[0], 0);
    EXPECT_EQ(statistics.getPidStatistics()[1].ptsHistogram[10 * time_step], 0);
    statistics.buildPtsHistogram(0, 3 * time_step);
    statistics.buildPtsHistogram(1, 15 * time_step);
    EXPECT_EQ(statistics.getPidStatistics()[0].ptsHistogram[0], 0u);
    EXPECT_EQ(statistics.getPidStatistics()[0].ptsHistogram[time_step], 3);
    EXPECT_EQ(statistics.getPidStatistics()[1].ptsHistogram[5 * time_step], 1);
}

/*!
 * Test that we build a DTS histogram based on time differences.
 */
TEST(TsStatisticsTests, TestDtsHistogram)
{
    TsStatistics statistics;
    int64_t time_step = 1 * 90000; // 1s time step
    statistics.buildDtsHistogram(0, 0);
    statistics.buildDtsHistogram(0, time_step);
    statistics.buildDtsHistogram(0, 2 * time_step);
    statistics.buildDtsHistogram(1, 10 * time_step);

    EXPECT_EQ(statistics.getPidStatistics()[0].dtsHistogram[0], 0u);
    EXPECT_EQ(statistics.getPidStatistics()[0].dtsHistogram[time_step], 2u);
    EXPECT_EQ(statistics.getPidStatistics()[1].dtsHistogram[0], 0);
    EXPECT_EQ(statistics.getPidStatistics()[1].dtsHistogram[10 * time_step], 0);
    statistics.buildDtsHistogram(0, 3 * time_step);
    statistics.buildDtsHistogram(1, 15 * time_step);
    EXPECT_EQ(statistics.getPidStatistics()[0].dtsHistogram[0], 0u);
    EXPECT_EQ(statistics.getPidStatistics()[0].dtsHistogram[time_step], 3);
    EXPECT_EQ(statistics.getPidStatistics()[1].dtsHistogram[5 * time_step], 1);
}

/*!
 * Test that we build a PCR histogram based on time differences.
 */
TEST(TsStatisticsTests, TestPcrHistogram)
{
    TsStatistics statistics;
    int64_t time_step = 1 * 90000; // 1s time step
    statistics.buildPcrHistogram(0, 0);
    statistics.buildPcrHistogram(0, time_step);
    statistics.buildPcrHistogram(0, 2 * time_step);
    statistics.buildPcrHistogram(1, 10 * time_step);

    EXPECT_EQ(statistics.getPidStatistics()[0].pcrHistogram[0], 0u);
    EXPECT_EQ(statistics.getPidStatistics()[0].pcrHistogram[time_step], 2u);
    EXPECT_EQ(statistics.getPidStatistics()[1].pcrHistogram[0], 0);
    EXPECT_EQ(statistics.getPidStatistics()[1].pcrHistogram[10 * time_step], 0);
    statistics.buildPcrHistogram(0, 3 * time_step);
    statistics.buildPcrHistogram(1, 15 * time_step);
    EXPECT_EQ(statistics.getPidStatistics()[0].pcrHistogram[0], 0u);
    EXPECT_EQ(statistics.getPidStatistics()[0].pcrHistogram[time_step], 3);
    EXPECT_EQ(statistics.getPidStatistics()[1].pcrHistogram[5 * time_step], 1);
}

/*!
 * Test ts-packet counter works.
 */
TEST(TsStatisticsTests, TestTsPacketCounter)
{
    mpeg2ts::TsDemuxer demuxer;
    EXPECT_EQ(demuxer.getTsCounters().mTsPacketCounter, 0u);

    demuxer.demux(packet_1);
    EXPECT_EQ(demuxer.getTsCounters().mTsPacketCounter, 1u);

    demuxer.demux(packet_2);
    EXPECT_EQ(demuxer.getTsCounters().mTsPacketCounter, 2u);

    demuxer.demux(packet_3);
    EXPECT_EQ(demuxer.getTsCounters().mTsPacketCounter, 3u);

    demuxer.demux(packet_4);
    EXPECT_EQ(demuxer.getTsCounters().mTsPacketCounter, 4u);

    demuxer.demux(pat_packet_1);
    EXPECT_EQ(demuxer.getTsCounters().mTsPacketCounter, 5u);
}
