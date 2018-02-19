#
# Simple makefile for ts-lib project
#
# Copyright © 2018 All rights reserved for skullanbones™
#
# Strictly Confidential - Do not duplicate or distribute without written
# permission from skullanbones™ and authors

COMPONENT_NAME ?= ts-lib

.PHONY: all clean

all:
	g++ main.cc TsParser.cc GetBits.cc -std=c++11 -o tsparser

clean:
	rm *.o
	rm tsparser
