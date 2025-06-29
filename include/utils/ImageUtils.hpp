#ifndef IMAGE_UTILS_HPP
#define IMAGE_UTILS_HPP 

#include <string>

class ImageUtils {
    public:
        static std::string getFileExtension(const std::string& filename);
        static std::string toLower(const std::string& str);
        static bool isSupportedFormat(const std::string& ext);
};

#endif // IMAGE_UTILS_HPP