#pragma once 
#include "Image.h"

class BMPImage : public Image {
public:
    BMPImage();
    bool load(const std::string& filename) override;
    int getWidth() const override;
    int getHeight() const override;
    ImageType getType() const override { return ImageType::BMP; }
    const std::vector<unsigned char>& getPixels() const override;

private:
    int width;
    int height;
    std::vector<unsigned char> pixels;
};