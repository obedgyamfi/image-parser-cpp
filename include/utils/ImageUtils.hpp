#ifndef IMAGE_UTILS_HPP
#define IMAGE_UTILS_HPP 

#include <string>
#include <vector>




class ImageUtils {
    public:
        static std::string getFileExtension(const std::string& filename);

        static std::string toLower(const std::string& str);

        static bool isSupportedFormat(const std::string& ext);

        std::vector<unsigned char> readImage_bytes(const std::string& imagePath);

};

#endif // IMAGE_UTILS_HPP