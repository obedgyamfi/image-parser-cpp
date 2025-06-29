#include <iostream>
#include <string>

#include "include/utils/Logger.hpp"
#include "include/utils/CLI.hpp"
#include "include/utils/ImageUtils.hpp"


int main(int argc , char* argv[]) {
    Logger log = Logger();
    CLI cli = CLI();
    CLIOptions opts = cli.parse(argc, argv);
    ImageUtils img_utils = ImageUtils();

    //std::string msg = "Hello, mother fucker";

    //log.info(msg);
    //log.warning(msg);
    //log.error(msg);

    std::string image_filename = opts.inputPath;
    std::string image_ext = img_utils.getFileExtension(image_filename);
    std::cout << "Image Extension: " << image_ext << std::endl;
    std::cout << "Image Path: " << image_filename << std::endl;

    if (img_utils.isSupportedFormat(image_ext)) {
        std::cout << "Image supported!" << std::endl;
    }
    else {
        std::cout << "Unsupported Image format!" << std::endl;
    }

   

    return 0;
}