#include "Image.hpp"
#include <stdexcept>

Image::Image(
    int width, int height,
    int bitDepth, int colorType) 
    : 
    width(0), height(0), 
    bitDepth(0), colorType(0) {
        pixels.resize(width * height);
    }

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

int Image::getBitDepth() const {
    return bitDepth;
}

int Image::getColorType() const {
    return colorType;
}

Image::Pixel Image::getPixel(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Pixel coordinates out of bounds");
    }
    return pixels[y * width + x];
}

void Image::setPixel(int x, int y, const Image::Pixel& pixel){
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Pixel coordinates out of bounds");
    }
    pixels[y * width + x] = pixel;
}

void Image::clear(Image::Pixel fillColor) {
    std::fill(pixels.begin(), pixels.end(), fillColor);
}



