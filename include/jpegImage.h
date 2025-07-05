#pragma once 
#include "Image.h"

class JPEGImage : public Image {
public:
    JPEGImage();
    bool load(const std::string& filename) override;
    int getWidth() const override;
    int getHeight() const override;
    ImageType getType() const override { return ImageType::JPEG; }
    const std::vector<unsigned char>& getPixels() const override;

private:
    int width;
    int height;
    std::vector<unsigned char> pixels;
};