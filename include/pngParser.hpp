#pragma once 

#include "ImageParser.hpp"

class PngParser : public ImageParser {
    Image parse(const std::vector<unsigned char>& imageBuffer) override;

    std::vector<unsigned char> read(const std::string& filepath) override;
};