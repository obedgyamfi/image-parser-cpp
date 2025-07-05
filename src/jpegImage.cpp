#include "jpegImage.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

JPEGImage::JPEGImage() : width(0), height(0) {}

bool JPEGImage::load(const std::string& filename) {
    // simply open file 
    std::ifstream file(filename, std::ios::binary);
    if(!file){
        std::cerr << "Cannot open JPEG file: " << filename << std::endl;
        return false;
    }

    // Check JPEG SOI marker
    unsigned char soi[2];
    file.read(reinterpret_cast<char*>(soi), 2);

    if(file.gcount() != 2 || soi[0] != 0xFF || soi[1] != 0xD8) {
        std::cerr << "Not a valid JPEG file: " << filename << std::endl;
        return false;
    }

    // Parse JPEG segments to find SOF0 (Start of Frame) for width/height
    while(file){
        unsigned char marker[2];
        file.read(reinterpret_cast<char*>(marker), 2);
        if (marker[0] != 0xFF) break;

        // skip padding bytes
        while(marker[1] == 0xFF) file.read(reinterpret_cast<char*>(&marker[1]), 1);

        // SOF0 (0xC0), SOF2(0xC2) are common
        if (marker[1] == 0xC0 || marker[1] == 0xC2) {
            unsigned char segment_length[2];
            file.read(reinterpret_cast<char*>(segment_length), 2);
            int length = (segment_length[0] << 8) + segment_length[1];

            unsigned char data[5];
            file.read(reinterpret_cast<char*>(data), 5);
            height = (data[1] << 8) + data[2];
            width = (data[3] << 8) + data[4];

            // pixels are not decoded here
            return true;
        } else {
            // skip segment
            unsigned char segment_length[2];
            file.read(reinterpret_cast<char*>(segment_length), 2);
            int length = (segment_length[0] << 8) + segment_length[1];
            if (length < 2) break;
            file.seekg(length - 2, std::ios::cur);
        }
    }

    std::cerr << "Could not find JPEG SOF marker for dimensions." << std::endl;
    return false;

}

int JPEGImage::getWidth() const {
    return width;
}

int JPEGImage::getHeight() const {
    return height;
}

const std::vector<unsigned char>& JPEGImage::getPixels() const {
    // not avalaible since JPEG has to be decompressed first 
    static std::vector<unsigned char> empty;
    return empty;
}