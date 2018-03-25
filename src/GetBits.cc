#include "GetBits.h"

GetBits::GetBits()
: mNumStoredBits{ 0 }
, mBitStore{ 0 }
, mSrcInx{ 0 }
, mSize{ 0 }
, mSrcBytes{ nullptr }
{
}

uint64_t GetBits::getBits(uint8_t requestedBits)
{
    uint64_t ret = 0;

    if (mSrcBytes == nullptr)
    {
        throw GetBitsException("null input data");
    }

    while (requestedBits > 0u)
    {
        if (mNumStoredBits == 0u)
        {
            if (mSrcInx >= mSize)
            {
                throw GetBitsException("Out of bound read");
            }

            mNumStoredBits = 8;
            mBitStore = mSrcBytes[mSrcInx++];
        }

        uint8_t bitsToFromStore = mNumStoredBits > requestedBits ? requestedBits : mNumStoredBits;
        ret = (ret << bitsToFromStore) | (mBitStore >> (8 - bitsToFromStore));

        requestedBits -= bitsToFromStore;
        mNumStoredBits -= bitsToFromStore;
        mBitStore <<= bitsToFromStore;
    }

    return ret;
};

void GetBits::resetBits(const uint8_t* srcBytes, size_t srcSize, size_t inx)
{
    mNumStoredBits = 0;
    mBitStore = 0;
    mSrcInx = inx;
    mSize = srcSize;
    mSrcBytes = srcBytes;
}

GetBitsException::GetBitsException(const std::string msg)
: mMsg{ msg }
{
}

size_t GetBits::getByteInx()
{
    return mNumStoredBits == 0 ? mSrcInx : mSrcInx - 1;
}
