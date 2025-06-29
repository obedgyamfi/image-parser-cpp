#include "utils/CLI.hpp"
#include <iostream>
#include <sstream>


CLIOptions CLI::parse(int argc, char* argv[]) {
    CLIOptions options;

    for (size_t i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if ((arg == "--input" || arg == "-i") && i + 1 < argc) {
            options.inputPath = argv[++i];
        } else if ((arg == "--output" || arg == "-o") && i + 1 < argc) {
            options.outputPath = argv[++i];
        } else if (arg == "--info") {
            options.showInfo = true;
        } else if ((arg == "--resize" || arg == "-r") && i + 1 < argc) {
            std::string dim = argv[++i];
            size_t xPos = dim.find('x');
            if (xPos != std::string::npos) {
                int width = std::stoi(dim.substr(0, xPos));
                int height = std::stoi(dim.substr(xPos + 1));
                options.resizeDimensions = std::make_pair(width, height);
            }
        } else if ( arg == "--convert" && i + 1 < argc) {
            options.convertFormat = argv[++i];
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
        }
    }

    return options;
}