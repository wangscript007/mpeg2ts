# Releases
*V0.3.0*
* [BUG-202] Fix TsUtilities crash when file not aligned to ts-packets
* [BUG-191] Add CPack and package both debug/release build
* [BUG-192] Add CMake finder for find_package
* [BUG-193] Run include-what-you-use
* [FEAT-181] Add include-what-you-use to CMake
* [x] Update use Ubuntu 18.04 CircleCI
* [FEAT-182] Improve Docker user
* [FEAT-178] Port Make to CMake
* [FEAT-174] Add cppcheck to CMake
* [x] Port component-tests to CMake
* [x] Port 3rd-party to CMake
* [x] Add CMake install target
* [x] Update CircleCI only use CMake
* [x] Add version number from CMake to tsparser
* [x] Add debug and release build
* [FEAT-175, FEAT-177] Improve CMake considerable using modern CMake

*V0.2.1*
* [x]  Fix build Release version and build issues (hotfix-0.2.1)

*V0.2*
* [x] Compile on Windows fixes
* [FEAT-163] Add codec parsers to TsUtilities
* [BUG-157] Codec parsers missing API
* [FEAT-166] Add micro google benchmark tests
* [BUG-161] Add H264/H262 unit tests
* [FEAT-158] Add benchmark tests
* [x] Add component tests to H264 parsing
* [x] Update README.
* [x] Apply C++ best practises (Lefticus)
* [x] Apply clang formating/analyze
* [FEAT-117] Use move instead of copying
* [FEAT-51/52] Add codec parsing (H264/H262)
* [FEAT-54] Add basic descriptor parsing
* [FEAT-128] Add CMake
* [FEAT-132] Add better code coverage
* [FEAT-126] Use Wextra and Wpedantic with GCC
* [FEAT-130] Add docker commands via bash
* [FEAT-32] Add code coverage
* [x] Added gtests to Windows proj
* [x] Merge TestTsLib.proj into mpeg2ts.sln
* [FEAT-102] Fixed some TODOs

*V0.1*

* Added first version of API (mpeg2ts.h)
* Added Windows support and build artifacts (mpeg2ts.lib/dll)
* Added Linux build artifacts (libmpeg2ts.so/a)
* Added high-level TsUtilities.h API for convinience
* Added first version H.264 support
* Added support for short version CLI for tsparser (Linux only)
* Fixed bug not finding and printing out error for settings.json

*V0.0.2.rc1*

* Add logging libary: Plog
* Fixed bug 68: Cannot parse Hbo Asset
* Add component-tests to CircleCi
* Fixed bug 66: Dolby asset caused crash
* Support Multiple Program Transport Streams (MPTS)
* Added file input --input option to CLI
* Fixed bug 49: Could not skip more than 64 bits in parser.
* Added non root user to Docker containers

*V0.0.1*

* build so lib
* Added es write
* fixed PCR bug
* Added build folder
* Added PES parsing
* Added multi PES cli option
* Added PMT parsing
* Added PAT parsing
* Added Demuxer