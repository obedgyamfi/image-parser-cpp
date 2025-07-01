#include <iostream>
#include <string>

#include "include/utils/Logger.hpp"
#include "include/utils/CLI.hpp"
// #include "include/utils/ImageUtils.hpp"
#include "include/Image.hpp"


int main(int argc , char* argv[]) {
    // initiailizing classes 
    CLI cli = CLI();
    CLIOptions opts = cli.parse(argc, argv);
    
    std::string image_path = opts.inputPath;

    // Image img = Image(opts.inputPath);




    


    return 0;
}