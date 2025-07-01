#include <iostream>
#include <string>

#include "include/utils/Logger.hpp"
#include "include/utils/CLI.hpp"
// #include "include/utils/ImageUtils.hpp"
#include "include/Image.hpp"
#include "include/pngParser.hpp"


int main(int argc , char* argv[]) {
    // initiailizing classes 
    CLI cli = CLI();
    PngParser png_parser = PngParser();
    CLIOptions opts = cli.parse(argc, argv);
    
    std::string image_path = opts.inputPath;

    std::vector<unsigned char> imgBuff = png_parser.read(image_path);
    // Image img = png_parser.parse(imgBuff);

    for(auto c : imgBuff) {
        std::cout << c << " ";
    }

    // Image img = Image(opts.inputPath);




    


    return 0;
}