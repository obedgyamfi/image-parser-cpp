#include "pngParser.hpp"
#include "utils/ImageUtils.hpp"
#include <iostream>

ImageUtils img_util = ImageUtils();

std::vector<unsigned char> PngParser::read(const std::string& filepath) {
    std::vector<unsigned char> image_buffer;
    if (img_util.isSupportedFormat(img_util.getFileExtension(filepath)))  {
        image_buffer = img_util.readImage_bytes(filepath);
    }
    return image_buffer;
}

// Image PngParser::parse(const std::vector<unsigned char>& imageBuffer) {
//     std::cout << "Parsing PNG data...." << std::endl;
//     return img;
// }

