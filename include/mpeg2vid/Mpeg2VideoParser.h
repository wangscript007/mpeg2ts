#pragma once

#include <map>
#include <vector>

/// Project files
#include "EsParser.h"
#include "GetBits.h"

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


    std::list<std::shared_ptr<EsInfo>> operator()(const uint8_t* from, std::size_t length) override;
    virtual std::list<std::shared_ptr<EsInfo>> analyze();

    std::vector<uint8_t> last;
    int foundStartCodes;
    std::vector<uint8_t> mPicture;
};
