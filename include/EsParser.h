#pragma once

#include "Types.h" // For ssize_t

#include <algorithm>
#include <cstdint>


class EsParser
{
public:
    EsParser()
    {
    }

    virtual ~EsParser()
    {
    }

    uint8_t* getFirstOne(const uint8_t* from, std::size_t length)
    {
        // TODO: avx2 can compare 32 bytes within one cycle
        //      and return pattern position using one more cycle
        return (uint8_t*)std::find((char*)from, (char*)from + length, 1);
    }

    virtual bool operator()(const uint8_t* /*from*/, size_t /*length*/)
    {
        return true;
    }
};
