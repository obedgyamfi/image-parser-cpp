#include "bmpImage.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

BMPImage::BMPImage() : width(0), height(0) {}

bool BMPImage::load(const std::string& filename) {
    // simply open file 
    std::ifstream file(filename, std::ios::binary);
    if(!file){
        std::cerr << "Cannot open BMP file: " << filename << std::endl;
        return false;
    }

    // create an array to store image bytes
    unsigned char header[54];
    file.read(reinterpret_cast<char*>(header), 54);

    if(file.gcount() != 54 || header[0] != 'B' || header[1] != 'M') {
        std::cerr << "Not a valid BMP file: " << filename << std::endl;
        return false;
    }

    // Load image info into class member variables
    width = *reinterpret_cast<int*>(&header[18]);
    height = *reinterpret_cast<int*>(&header[22]);
    int bitsPerPixel = *reinterpret_cast<short*>(&header[28]);
    
    // check bitsPerPixel supported
    if(bitsPerPixel != 24){
        std::cerr << "Only 24-bit BMP supported." << std::endl;
        return false;
    }

    // Reading pixles
    int row_padded = (width * 3 + 3) & (~3);
    pixels.resize(row_padded * height);
    file.read(reinterpret_cast<char*>(pixels.data()), pixels.size());
    if(!file){
        std::cerr << "Error reading BMP Pixel data." << std::endl;
        return false;
    }
    return true;
}

int BMPImage::getWidth() const {
    return width;
}

int BMPImage::getHeight() const {
    return height;
}

const std::vector<unsigned char>& BMPImage::getPixels() const {
    return pixels;
}