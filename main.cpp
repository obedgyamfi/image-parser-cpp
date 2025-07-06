#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "ImageFactory.h"


int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return 1;
    }    

    std::string file_path = argv[2];
    std::cout << "File path: " << file_path << std::endl;

    auto image = ImageFactory::create(file_path);

    if(!image) {
        std::cerr << "Umsupported or unrecognized image file extension." << std::endl;
        return 1;
    }

    if(!image->load(file_path)) {
        std::cerr << "Failed to load image or extract metadata." << std::endl; 
        return 1;
    }

    std::cout << "Image loaded successfully!" << std::endl;
    std::cout << "Width: " << image->getWidth() << std::endl;
    std::cout << "Height: " << image->getHeight() << std::endl;
    std::cout << "Type: ";
    switch(image->getType()) {
        case ImageType::BMP: std::cout << "BMP"; break;
        case ImageType::JPEG: std::cout << "JPEG"; break;
        case ImageType::PNG: std::cout << "PNG"; break;
        default: std::cout << "Unknown"; break;
    }
    std::cout << std::endl;

    return 0;
}

