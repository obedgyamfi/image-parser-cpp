#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

bool is_image(const std::string& filename);
bool is_png(const std::string& filename);
bool is_jpeg(const std::string& filename);
bool is_bmp(const std::string& filename);
bool is_path_valid(const std::string& filename);

int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return 1;
    }    

    std::string file_path = argv[2];
    std::cout << "File path: " << file_path << std::endl;

    // Check if image file is valid
    if (!is_path_valid(file_path)){
        return 1;
    }

    std::cout << "Image file is valid and recognized." << std::endl;

    return 0;
}


// Checks if the input file is an image
bool is_image(const std::string& filename){
    std::string ext = filename.substr(filename.find_last_of('.') + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    std::cout << "Extension: " << ext << std::endl;

    if(ext != "jpg" && ext != "jpeg" && ext != "bmp"){
        std::cerr << "Error: Unsupported file extension" << std::endl;
            return false;
    }
    
    return is_bmp(filename) || is_jpeg(filename) || is_png(filename);
}


// Checks if the input file path is valid
bool is_path_valid(const std::string& filename){
    std::ifstream path(filename);
    if(!path){
        std::cerr << "Error: File does not exist or cannot be opened: " << filename << std::endl;
        return false;
    }
    path.close();

    if (!is_image(filename)){
        std::cerr << "Error: File is not an image" << std::endl;
        return false;
    }

    return true;
}

// // Checks if image is png
bool is_png(const std::string& filename) {
    static const unsigned char png_signature[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    std::ifstream img_file(filename, std::ios::binary);

    unsigned char header[8];
    img_file.read(reinterpret_cast<char*>(header), 8);
    return img_file.gcount() == 8 && std::equal(header, header+8, png_signature);
}

// Checks if image is bmp
bool is_bmp(const std::string& filename){
    std::ifstream file(filename, std::ios::binary);
    if(!file) return false;
    char header[2] = {0};
    file.read(header, 2);
    return file.gcount() == 2 && header[0] == 'B' && header[1] == 'M';
}

// Checks if image is jpeg
bool is_jpeg(const std::string& filename){
    std::ifstream file(filename, std::ios::binary);
    if(!file) return false;
    unsigned char header[2] = {0};
    file.read(reinterpret_cast<char*>(header), 2);

    std::cout << "DEBUG: JPEG hex: " << header[0] << " " << header[1] << std::endl;
    return file.gcount() == 2 && header[0] == 0xFF && header[1] == 0xD8;
}
