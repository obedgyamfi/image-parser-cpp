#pragma once 

#include "ImageParser.hpp"
// #include "Image.hpp"

class PngParser : public ImageParser {
public:
    // Image parse(const std::vector<unsigned char>& imageBuffer) override;

    std::vector<unsigned char> read(const std::string& filepath) override;
};