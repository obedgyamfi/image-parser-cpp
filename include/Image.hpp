#ifndef IMAGE_HPP
#define IMAGE_HPP 

#include <vector>
#include <string>
#include <cstdint>

class Image {
public:
    struct Pixel {
        uint8_t r, g, b, a;
    };

    Image(int width, int height, int bitDepth = 8, int colorType = 6);

    int getWidth() const;
    int getHeight() const;
    int getBitDepth() const;
    int getColorType() const;

    Pixel getPixel(int x, int y) const;
    void setPixel(int x, int y, const Pixel& pixel);

    void clear(Pixel fillColor = {0, 0, 0, 0});
private:
    int bitDepth, colorType;
    int width, height;
    std::vector<Pixel> pixels;
};


#endif // IMAGE_HPP