#pragma once

#include <map>
#include <vector>

/// Project files
#include "EsParser.h"
#include "GetBits.h"

struct EsInfoMpeg2 : public EsInfo
{
    //    EsInfoMpeg2(int picture, const std::string& msg)
    //        : picture{picture}, msg{msg} {}
    int picture; // slice
    std::string msg;
};

struct EsInfoMpeg2PictureSliceCode : public EsInfoMpeg2
{
    int picType; // I, B, P
};

struct EsInfoMpeg2SequenceHeader : public EsInfoMpeg2
{
    int width, height;
    std::string aspect;
    std::string framerate;
};

class Mpeg2VideoEsParser : public GetBits, public EsParser
{
    static std::map<uint8_t, std::string> AspectToString;
    static std::map<uint8_t, std::string> FrameRateToString;

public:
    Mpeg2VideoEsParser(const Mpeg2VideoEsParser& arg) = delete;
    Mpeg2VideoEsParser& operator=(const Mpeg2VideoEsParser& arg) = delete;

    Mpeg2VideoEsParser()
        : foundStartCodes{ 0 }
    {
    }

    virtual ~Mpeg2VideoEsParser() = default;


    std::vector<std::shared_ptr<EsInfo>> operator()(const uint8_t* from, std::size_t length) override;
    virtual std::vector<std::shared_ptr<EsInfo>> analyze();

    int foundStartCodes;
    std::vector<uint8_t> mPicture;
};
