#include "ImageFactory.h"
#include "bmpImage.h"
#include "pngImage.h"
#include "jpegImage.h"
#include <algorithm>

std::unique_ptr<Image> ImageFactory::create(const std::string& filename) {
    // Get file extension in lower case 
    auto pos = filename.find_last_of('.');
    if (pos == std::string::npos) return nullptr;
    std::string ext = filename.substr(pos+1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

    if (ext == "bmp"){
        return std::make_unique<BMPImage>();
    } else if (ext == "png") {
        return std::make_unique<PNGImage>();
    } else if (ext == "jpg" || ext == "jpeg") {
        return std::make_unique<JPEGImage>();
    }
    return nullptr;
}
