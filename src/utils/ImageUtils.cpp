#include "utils/ImageUtils.hpp"
#include <algorithm>

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