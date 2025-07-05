#include "pngImage.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

PNGImage::PNGImage() : width(0), height(0) {}

bool PNGImage::load(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if(!file){
        std::cerr << "Cannot open PNG file: " << filename << std::endl;
        return false;
    }

    // Check PNG signature
    unsigned char signature[8]; 
    file.read(reinterpret_cast<char*>(signature), 8);
    const unsigned char png_signature[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    if(::memcmp(signature, png_signature, 8) != 0) {
        std::cerr << "not a valid PNG file: " << filename << std::endl;
        return false;
    }

    // Read chunks to find IHDR
    while(file){
        unsigned char length_bytes[4];
        file.read(reinterpret_cast<char*>(length_bytes), 4);
        if(file.gcount() != 4) break;
        unsigned int length = (length_bytes[0] << 24) | (length_bytes[1] << 16) | (length_bytes[2] << 8) | length_bytes[3];

        char chunk_type[5] = {0};
        file.read(chunk_type, 4);
        if(file.gcount() != 4) break;

        if(std::string(chunk_type, 4) == "IHDR"){
            unsigned char ihdr[8];
            file.read(reinterpret_cast<char*>(ihdr), 8);
            width = (ihdr[0] << 24) | (ihdr[1] << 16) | (ihdr[2] << 8) | ihdr[3] << 3;
            height = (ihdr[4] << 24) | (ihdr[5] << 16) | (ihdr[6] << 8) | ihdr[7] << 3;
            return true;
        } else {
            // skip chunk data + CRC
            file.seekg(length + 4, std::ios::cur);
        }
    }

    std::cerr << "Could not find PNG IHDR chunk for dimensions." << std::endl;
    return false;
}

int PNGImage::getWidth() const {
    return width;
}

int PNGImage::getHeight() const {
    return height;
}

const std::vector<unsigned char>& PNGImage::getPixels() const {
    // Not implemented: PNG pixels are compressed
    static std::vector<unsigned char> empty;
    return empty;

}