// TestTsLib.cpp : Defines the entry point for the console application.
//

#include "public/mpeg2ts.h"
#include "public/TsUtilities.h"
#include <iostream>

/*!
* PID: 0
* PAT packet
*
*/
const uint8_t pat_packet_1[] =
{ 0x47, 0x40, 0x00, 0x18, 0x00, 0x00, 0xb0, 0x0d, 0x00, 0x01, 0xc1, 0x00, 0x00, 0x00, 0x01, 0xe2,
0x56, 0xf8, 0x03, 0xe7, 0x1b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

//using namespace tslib;

void PATCallback(PsiTable* table, uint16_t pid, void* hdl) {
	std::cout << "came here PATCallback" << std::endl;

    PatTable* pat;
    try
    {
        pat = dynamic_cast<PatTable*>(table);
    }
    catch (std::exception& ex)
    {
        std::cerr << "ERROR: dynamic_cast ex: " << ex.what();
        return;
    }

    std::cout << "Got PAT callback with PMT PID: " << pat->programs.at(0).program_map_PID << std::endl;
}

int main()
{
    // TsUtilities High level API
    tsutil::TsUtilities util;
    //util.parseTransportStreamData(pat_packet_1, 188);
    
    bool success = util.parseTransportFile("../../../../assets/bbc_one.ts");
    if (!success)
    {
        std::cerr << "Could not open file" << std::endl;
        system("PAUSE");
        return EXIT_FAILURE;
    }

    //std::cout << "Got PAT: " << pat << std::endl;
    PatTable pat = util.getPatTable();
    try
    {   
        std::cout << "Got PAT with PMT PIDd: " << pat.programs.at(0).program_map_PID << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Got exception..." << e.what() << std::endl;
    }
    std::vector<uint16_t> pmtPids = util.getPmtPids();
    for (auto pid : pmtPids)
    {
        std::cout << "Got PMT pid: " << pid << std::endl;
    }
    std::map<uint16_t, PmtTable> pmtTables = util.getPmtTables();


    for (auto pid : pmtPids)
    {
        for (auto stream : pmtTables[pid].streams)
        {
            std::cout << "Found elementary stream in PMT :" << stream.elementary_PID << std::endl;
        }
    }

    /*for (auto& kv : pmtTables) {
        std::cout << "PMT PID: " << kv.first << " has PMT " << kv.second << std::endl;
    }

    try
    {
        std::cout << "Size of pmtTables: " << pmtTables.size() << std::endl;
        std::cout << "Got PMT with first stream PID: " << pmtTables[pmtPids.at(0)].streams.at(0).elementary_PID << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Got exception..." << e.what() << std::endl;
    }*/

    // Low level API
    /*
	mpeg2ts::TsDemuxer demuxer;

	demuxer.addPsiPid(0, std::bind(&PATCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), nullptr);

	demuxer.demux(pat_packet_1);*/

	system("PAUSE");
    return 0;
}

