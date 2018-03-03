//
// Created by microlab on 2/24/18.
//

#pragma once

#include <stdint.h>


/*AF len: 136
hasAdaptationField: 1
pcr: 0
opcr: 0
payloadSize: 47
payloadStartOffset: 141
*/
const uint8_t packet_1[] = { 0x47, 0x01, 0x21, 0x30, 0x88, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
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
const uint8_t packet_2[] = { 0x47, 0x02, 0x57, 0x20, 0xb7, 0x10, 0x3b, 0x9b, 0xb3, 0x1e, 0xff, 0x26,
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
const uint8_t packet_3[] = { 0x47, 0x41, 0x21, 0x1c, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x80, 0x90,
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


/*
 * PID: 481
 * hasAdaptationField: 0
 * payloadSize: 184
 * payloadStartOffset: 4
 * */
const uint8_t packet_4[] = { 0x47, 0x01, 0xe1, 0x10, 0x9d, 0xcb, 0xa6, 0xcf, 0x7b, 0x6a, 0xa4, 0x60,
                             0x5f, 0x34, 0x48, 0xd7, 0xaa, 0x06, 0x4b, 0x55, 0xdf, 0x4a, 0x20, 0x2a,
                             0xb4, 0x9b, 0x21, 0x5c, 0x6e, 0xd9, 0x46, 0x3d, 0x5b, 0x06, 0xa5, 0x2a,
                             0x5e, 0x3c, 0xdd, 0x71, 0x87, 0x0f, 0x30, 0xcd, 0x5a, 0x77, 0x27, 0xe1,
                             0xe4, 0xe9, 0x89, 0xbf, 0xf8, 0xe1, 0x21, 0xf6, 0x09, 0x59, 0xa1, 0x41,
                             0x1c, 0x0f, 0x31, 0x4d, 0x29, 0xe2, 0xdb, 0x5c, 0x6b, 0xb3, 0xf5, 0x37,
                             0x39, 0x24, 0xcd, 0x75, 0x53, 0x87, 0x20, 0x1e, 0x9a, 0x90, 0xb1, 0x13,
                             0xc6, 0x9f, 0x29, 0x9d, 0xd8, 0xd0, 0xca, 0xea, 0xf5, 0xf6, 0xbf, 0x8a,
                             0x4e, 0x93, 0xb0, 0x0c, 0x94, 0x7a, 0xe9, 0x29, 0xb1, 0xe5, 0x05, 0x46,
                             0x87, 0x04, 0xb2, 0xd9, 0x6e, 0x3a, 0x81, 0x5e, 0x60, 0x68, 0x6c, 0x94,
                             0xdb, 0xd0, 0xb8, 0xf3, 0x25, 0xd1, 0x37, 0xf2, 0x6d, 0x70, 0x43, 0x2c,
                             0x8e, 0x65, 0x59, 0x0d, 0x75, 0xd0, 0x86, 0x72, 0xfb, 0x47, 0xa1, 0xbe,
                             0xda, 0x2b, 0x44, 0xa9, 0x76, 0xf2, 0x0a, 0xb7, 0x1c, 0x1b, 0x47, 0x3a,
                             0x0c, 0x54, 0x86, 0x85, 0x1f, 0x6c, 0xd3, 0x79, 0xdd, 0x7f, 0xbf, 0x3b,
                             0x67, 0x58, 0x3b, 0xaf, 0x4c, 0x01, 0x86, 0xc0, 0xe1, 0x47, 0xce, 0xb5,
                             0x2c, 0x06, 0xca, 0x16, 0xf7, 0x26, 0x99, 0x3e };

/*
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


/*!
 *
 * Taken from:
 * https://www.lysator.liu.se/upplysning/fa/DVB-uppLYSning.pdf
 *
 * Example: PAT — Swedish Terrestrial MUX1
 * Here is an example from a live broadcast of the Swedish terrestrial
 * MUX1, where the raw data of the Program Association Table was:
 * 00 b0 4d 03 fd c3 00 00 00 00 e0 10 14 3c f4 3c
 * 13 ba f3 ba 13 ce f3 ce 15 a4 f5 a4 04 d8 e4 d8
 * 16 08 f6 08 03 f2 e3 f2 16 d0 f6 d0 16 a8 f6 a8
 * 05 0a e5 0a 05 00 e5 00 03 66 e3 66 ff fe e7 12
 * 0b c2 eb c2 0b cc eb cc 0b d6 eb d6 e8 ca 31 cb
 * The first eight bytes are the Table header, which decodes as follows:
 * 00 Table Type for PAT
 * b0 4d Size: 0x04d bytes after the length field
 * 03 fd Table Extension: 0x03fd (TSID)
 * c3 Table version information
 * 00 00 This section is number 0, last section is number 0
 * The last four bytes are a 32-bit CRC checksum. The rest is a list of
 * 32-bit entries containing the following information:
 * Program 0(0x0) PID=16(0x10)
 * Program 5180(0x143c) PID=5180(0x143c)
 * Program 5050(0x13ba) PID=5050(0x13ba)
 * Program 5070(0x13ce) PID=5070(0x13ce)
 * Program 5540(0x15a4) PID=5540(0x15a4)
 * Program 1240(0x4d8) PID=1240(0x4d8)
 * Program 5640(0x1608) PID=5640(0x1608)
 * Program 1010(0x3f2) PID=1010(0x3f2)
 * Program 5840(0x16d0) PID=5840(0x16d0)
 * Program 5800(0x16a8) PID=5800(0x16a8)
 * Program 1290(0x50a) PID=1290(0x50a)
 * Program 1280(0x500) PID=1280(0x500)
 * Program 870(0x366) PID=870(0x366)
 * Program 65534(0xfffe) PID=1810(0x712)
 * Program 3010(0xbc2) PID=3010(0xbc2)
 * Program 3020(0xbcc) PID=3020(0xbcc)
 * Program 3030(0xbd6) PID=3030(0xbd6)
 * Note 1: Program 0 is not a real program; it’s used to indicate the PID where
 * network information is broadcast.
 * Note 2: the Swedish operator, Teracom, has chosen to use the same number for PID
 * and Program Number for most of the programs, so Program 870 has it’s PMTs on
 * PID 870. But not all operators do this, and it isn’t possible to do it generally, since
 * the Program Number is a 16-bit value, but the PID is only a 13-bit value.
 */
const uint8_t pat_packet_2[] =
{ 0x47, 0x40, 0x00, 0x18, 0x00, 0x00, 0xb0, 0x4d, 0x03, 0xfd, 0xc3, 0x00, 0x00, 0x00, 0x00, 0xe0,
  0x10, 0x14, 0x3c, 0xf4, 0x3c, 0x13, 0xba, 0xf3, 0xba, 0x13, 0xce, 0xf3, 0xce, 0x15, 0xa4, 0xf5,
  0xa4, 0x04, 0xd8, 0xe4, 0xd8, 0x16, 0x08, 0xf6, 0x08, 0x03, 0xf2, 0xe3, 0xf2, 0x16, 0xd0, 0xf6,
  0xd0, 0x16, 0xa8, 0xf6, 0xa8, 0x05, 0x0a, 0xe5, 0x0a, 0x05, 0x00, 0xe5, 0x00, 0x03, 0x66, 0xe3,
  0x66, 0xff, 0xfe, 0xe7, 0x12, 0x0b, 0xc2, 0xeb, 0xc2, 0x0b, 0xcc, 0xeb, 0xcc, 0x0b, 0xd6, 0xeb,
  0xd6, 0xe8, 0xca, 0x31, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/*!
 * Continuing with the same recorded data as for the PAT in the previous
 * example, this was the raw data of the PMT on PID 1010, for Program
 * 1010:

 * The first eight bytes are the Table header:
 * 02          Table Type for PMT
 * b0 34       Size: 0x034 bytes after the length field
 * 03 f2       Table Extension: 0x03f2 (Program Number)
 * ed          Table version information
 * 00 00       This section is number 0, last section is number 0

 * After the header, the first two bytes (e3 fb) are the PCR PID, but
 * only the lowest 13 bits are used, giving the value: 0x03fb.
 * After the PCR PID, there is a Program Descriptor Loop, with first 4
 * unused bits, then a 12-bit length field, and then the Descriptor data.
 * But in this case, the data is f0 00, giving a value of 0 for the length
 * field, meaning no Descriptor data is present.
 * The remaining data is a list of Elementary Streams, which decodes to
 * the following information:
 * ESPID=1004(0x3ec), type=6(0x6)
 * teletext_descriptor
 * (RAW DATA: 56 05 73 77 65 09 00)
 * ESPID=1018(0x3fa), type=3(0x3)
 * ESPID=1017(0x3f9), type=6(0x6)
 * AC-3_descriptor
 * (RAW DATA: 6a 01 00)
 * stream_identifier_descriptor, tag: 189(0xbd)
 * (RAW DATA: 52 01 bd)
 * registration_descriptor
 * (RAW DATA: 05 04 41 43 2d 33)
 * ESPID=1019(0x3fb), type=2(0x2)
 */
const uint8_t pmt_packet_1[] =
{ 0x47, 0x43, 0xF2, 0x18, 0x00, 0x02, 0xb0, 0x34, 0x03, 0xf2, 0xed, 0x00, 0x00, 0xe3, 0xfb, 0xf0,
  0x00, 0x06, 0xe3, 0xec, 0xf0, 0x07, 0x56, 0x05, 0x73, 0x77, 0x65, 0x09, 0x00, 0x03, 0xe3, 0xfa,
  0xf0, 0x00, 0x06, 0xe3, 0xf9, 0xf0, 0x0c, 0x6a, 0x01, 0x00, 0x52, 0x01, 0xbd, 0x05, 0x04, 0x41,
  0x43, 0x2d, 0x33, 0x02, 0xe3, 0xfb, 0xf0, 0x00, 0xa1, 0xd9, 0x4a, 0x10, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
