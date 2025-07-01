#include "pngParser.hpp"
#include "utils/ImageUtils.hpp"
#include <iostream>

ImageUtils img_util = ImageUtils();

std::vector<unsigned char> read(const std::string& filepath) {
    if (img_util.isSupportedFormat(img_util.getFileExtension(filepath)))  {
        std::vector<unsigned char> image_buffer = img_util.readImage_bytes(filepath);

        return image_buffer;
    }
}

Image PngParser::parse(const std::vector<unsigned char>& imageBuffer) {
    
}

