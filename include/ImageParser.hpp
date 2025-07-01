#pragma once 

#include <string>
#include <vector>
#include "Image.hpp"


// This is an abstract base class
class ImageParser {
public:
    virtual ~ImageParser() = default;

    // virtual Image parse(const std::vector<unsigned char>& imageBuffer) = 0;

    virtual std::vector<unsigned char> read(const std::string& filepath) = 0;

};

