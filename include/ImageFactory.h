#pragma once 
#include "Image.h"
#include <memory>

class ImageFactory {
public:
    static std::unique_ptr<Image> create(const std::string& filename);
};