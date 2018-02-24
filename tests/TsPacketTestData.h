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
const uint8_t packet_4[] = {
        0x47, 0x01, 0xe1, 0x10, 0x9d, 0xcb, 0xa6, 0xcf, 0x7b, 0x6a, 0xa4, 0x60, 0x5f, 0x34, 0x48, 0xd7, 0xaa, 0x06, 0x4b,
        0x55, 0xdf, 0x4a, 0x20, 0x2a, 0xb4, 0x9b, 0x21, 0x5c, 0x6e, 0xd9, 0x46, 0x3d, 0x5b, 0x06, 0xa5, 0x2a, 0x5e, 0x3c,
        0xdd, 0x71, 0x87, 0x0f, 0x30, 0xcd, 0x5a, 0x77, 0x27, 0xe1, 0xe4, 0xe9, 0x89, 0xbf, 0xf8, 0xe1, 0x21, 0xf6, 0x09,
        0x59, 0xa1, 0x41, 0x1c, 0x0f, 0x31, 0x4d, 0x29, 0xe2, 0xdb, 0x5c, 0x6b, 0xb3, 0xf5, 0x37, 0x39, 0x24, 0xcd, 0x75,
        0x53, 0x87, 0x20, 0x1e, 0x9a, 0x90, 0xb1, 0x13, 0xc6, 0x9f, 0x29, 0x9d, 0xd8, 0xd0, 0xca, 0xea, 0xf5, 0xf6, 0xbf,
        0x8a, 0x4e, 0x93, 0xb0, 0x0c, 0x94, 0x7a, 0xe9, 0x29, 0xb1, 0xe5, 0x05, 0x46, 0x87, 0x04, 0xb2, 0xd9, 0x6e, 0x3a,
        0x81, 0x5e, 0x60, 0x68, 0x6c, 0x94, 0xdb, 0xd0, 0xb8, 0xf3, 0x25, 0xd1, 0x37, 0xf2, 0x6d, 0x70, 0x43, 0x2c, 0x8e,
        0x65, 0x59, 0x0d, 0x75, 0xd0, 0x86, 0x72, 0xfb, 0x47, 0xa1, 0xbe, 0xda, 0x2b, 0x44, 0xa9, 0x76, 0xf2, 0x0a, 0xb7,
        0x1c, 0x1b, 0x47, 0x3a, 0x0c, 0x54, 0x86, 0x85, 0x1f, 0x6c, 0xd3, 0x79, 0xdd, 0x7f, 0xbf, 0x3b, 0x67, 0x58, 0x3b,
        0xaf, 0x4c, 0x01, 0x86, 0xc0, 0xe1, 0x47, 0xce, 0xb5, 0x2c, 0x06, 0xca, 0x16, 0xf7, 0x26, 0x99, 0x3e};
