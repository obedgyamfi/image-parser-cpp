#include "utils/ImageUtils.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

std::string ImageUtils::getFileExtension(const std::string& filename) {
    size_t dot = filename.find_last_of('.');
    if(dot != std::string::npos && dot + 1 < filename.size()){
        return toLower(filename.substr(dot + 1));
    }
    return "";
}

std::string ImageUtils::toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });

    return result;
}

bool ImageUtils::isSupportedFormat(const std::string& ext) {
    return ext == "png" || ext == "jpg" || ext == "jpeg" || ext == "bmp";
}

std::vector<unsigned char> ImageUtils::readImage_bytes(const std::string& imagePath) {
    std::ifstream image_file(imagePath, std::ios::binary | std::ios::ate);
    if(!image_file.is_open()){
        std::cerr << "Error: Can't open image, Image not found!" << std::endl;
    }
    
    // getting the file size
    std::streamsize fileSize = image_file.tellg();
    image_file.seekg(0, std::ios::beg);

    // read all bytes into a vector
    std::vector<unsigned char> imageBuffer(fileSize);
    if(!image_file.read(reinterpret_cast<char*>(imageBuffer.data()), fileSize)){
        std::cerr << "Error: Failed to read the image file!" << std::endl;
        return {};
    }

    return imageBuffer;
}