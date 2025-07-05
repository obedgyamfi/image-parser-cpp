#pragma once 
#include <string>
#include <vector>

enum class ImageType { UKNOWN, BMP, JPEG, PNG};

class Image {
public:
    virtual ~Image() = default;
    virtual bool load(const std::string& filename) = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual ImageType getType() const = 0;
    virtual const std::vector<unsigned char>& getPixels() const = 0;
};

