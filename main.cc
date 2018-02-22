/**
 * Strictly Confidential - Do not duplicate or distribute without written
 * permission from authors
 */
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>

#include "TsPacketInfo.h"
#include "TsParser.h"
#include "TsDemuxer.h"

#include <type_traits>

/*AF len: 136
hasAdaptationField: 1
pcr: 0
opcr: 0
payloadSize: 47
payloadStartOffset: 141
*/
unsigned char packet_1[] = { 0x47, 0x01, 0x21, 0x30, 0x88, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4c, 0x1f, 0xce,
                             0xea, 0x7b, 0x82, 0xc7, 0xb9, 0xbd, 0xfb, 0x4d, 0x13, 0x2c, 0xeb, 0xa9,
                             0xe4, 0xed, 0x42, 0xee, 0x9a, 0x5b, 0x27, 0xc5, 0x76, 0xf6, 0x28, 0xad,
                             0x7e, 0xad, 0x67, 0xe2, 0xed, 0xfd, 0x66, 0xee, 0x92, 0xf9, 0xd2, 0x63,
                             0x00, 0xd2, 0x18, 0xf7, 0x95, 0xa4, 0x17, 0xe7 };

/*AF len: 183
hasAdaptationField: 1
pcr: 600035807394
opcr: 0
no payload
*/
unsigned char packet_2[] = { 0x47, 0x02, 0x57, 0x20, 0xb7, 0x10, 0x3b, 0x9b, 0xb3, 0x1e, 0xff, 0x26,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/*
PID: 289
hasAdaptationField: 0
pcr: 0
opcr: 0
payloadSize: 184
payloadStartOffset: 4
*/
unsigned char packet_3[] = { 0x47, 0x41, 0x21, 0x1c, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x80, 0x90,
                             0x08, 0x23, 0xdc, 0xf1, 0x29, 0x19, 0x80, 0x88, 0xb9, 0x96, 0x8a, 0xad,
                             0x73, 0x13, 0x0a, 0x9e, 0x3c, 0x64, 0xce, 0xf0, 0x19, 0xbd, 0x7d, 0xf0,
                             0xc2, 0x3c, 0x82, 0xbc, 0xb3, 0x9a, 0x63, 0xe8, 0xa6, 0x4d, 0x5a, 0xc8,
                             0xe9, 0x0c, 0x24, 0x93, 0xc0, 0x2a, 0x1d, 0x08, 0x22, 0x20, 0x4a, 0x48,
                             0xf3, 0xe3, 0xb6, 0xb3, 0x8c, 0x20, 0x05, 0xf2, 0xe5, 0xb7, 0x03, 0xe0,
                             0x9c, 0x6c, 0x94, 0xf8, 0x3c, 0xba, 0xc2, 0x05, 0x74, 0x24, 0x77, 0x6d,
                             0xcc, 0x13, 0x1f, 0x39, 0xf0, 0x38, 0xf7, 0x48, 0xee, 0x6a, 0x06, 0x15,
                             0x8c, 0x9b, 0x31, 0xfa, 0x2a, 0xac, 0xfe, 0xf6, 0x42, 0x06, 0xc9, 0xc1,
                             0xc5, 0x05, 0x78, 0xb5, 0xb1, 0xd1, 0xda, 0x02, 0x70, 0xb4, 0x38, 0xb5,
                             0x3d, 0x99, 0x9e, 0xc0, 0x6d, 0xc9, 0xdf, 0x24, 0xe0, 0x97, 0xb9, 0xb5,
                             0x2c, 0xab, 0x7d, 0x4b, 0x4c, 0x08, 0x8d, 0x2a, 0x22, 0x99, 0xbd, 0xd3,
                             0x5f, 0x54, 0x01, 0xe4, 0x38, 0x00, 0x00, 0x00, 0x01, 0x09, 0x50, 0x00,
                             0x00, 0x01, 0x06, 0x01, 0x01, 0x04, 0x04, 0x09, 0xb5, 0x00, 0x31, 0x44,
                             0x54, 0x47, 0x31, 0x41, 0xf8, 0x80, 0x00, 0x00, 0x01, 0x01, 0x9e, 0x36,
                             0xc5, 0xe4, 0x67, 0xfe, 0x7a, 0xa5, 0xa2, 0xc3 };

unsigned long count = 0;
unsigned long countAdaptPacket = 0;

void TsCallback(unsigned char packet, TsPacketInfo tsPacketInfo)
{
    (void)packet;
    std::cout << "demuxed TS packet \n" << tsPacketInfo.toString();
}

void PSICallback(const PsiTable& table)
{
    std::cout << "demuxed PSI table \n" << table.id;
}

void PESCallback(const PesPacket& pes)
{
    std::cout << "demuxed PES packet \n";
}

int main(int, char**)
{
    std::cout << "Staring parser of stdout" << std::endl;

    unsigned long count;

    // Specify input stream
    setvbuf(stdout, NULL, _IOLBF, 0);

    //  char buffer[200*10224*1024];
    //  setbuf(stdin, buffer);

    unsigned long position = 0;

    TsPacketInfo tsPacketInfo = { 0 };
    TsParser tsParser;
    
    TsDemuxer tsDemux;
    tsDemux.addPid(0, std::bind(&PSICallback, std::placeholders::_1));

    TsAdaptationFieldHeader fieldHeader;

    std::cout << std::boolalpha;
    std::cout << std::is_pod<TsHeader>::value << '\n';
    std::cout << std::is_pod<TsAdaptationFieldHeader>::value << '\n';

    /*
    TODO: move it to gtest
    tsParser.parseTsPacketInfo(packet_3, tsPacketInfo);
    std::cout << tsPacketInfo.toString() << std::endl;
    return 0;*/

    for (count = 0;; ++count)
    {

        unsigned char packet[TS_PACKET_SIZE];
        // SYNC
        // Check for the sync byte. When found start a new ts-packet parser...
        char b;


        b = getchar();
        while (b != TS_PACKET_SYNC_BYTE)
        {
            b = getchar();
            if (b == EOF)
            {
                std::cout << "End Of File..." << std::endl;
                std::cout << "Found " << count << " ts-packets." << std::endl;
                std::cout << "Found Adaptation Field packets:" << countAdaptPacket << " ts-packets."
                          << std::endl;
                return EXIT_SUCCESS;
            }
        }


        /*
        while (buffer[position++] != TS_PACKET_SYNC_BYTE) {
          if (buffer[position] == EOF)
             {
               std::cout << "End Of File..." << std::endl;
               std::cout << "Found " << count << " ts-packets." << std::endl;
          std::cout << "Found Adaptation Field packets:" << countAdaptPacket
                << " ts-packets." << std::endl;
               return EXIT_SUCCESS;
             }
        }
        */

        // TS Packet start
        packet[0] = b;

        // Read TS Packet from stdin
        size_t res =
        fread(packet + 1, 1, TS_PACKET_SIZE - 1, stdin); // Copy only packet-size - sync byte
        // memcpy(packet, &buffer[position], TS_PACKET_SIZE);


        tsParser.parseTsPacketInfo(packet, tsPacketInfo);
        std::cout << tsPacketInfo.toString() << std::endl;

        tsDemux.demux(packet, tsPacketInfo);

        if (tsPacketInfo.hasAdaptationField)
        {
            //      printf("found packet with adaptation field");
            countAdaptPacket++;

            if (countAdaptPacket == 1)
            {
                for (int i = 0; i < TS_PACKET_SIZE; i++)
                {
                    //	  printf("0x%1x, ", packet[i]);
                }
            }
        }

    } // for loop
}
