#ifndef CLI_HPP
#define CLI_HPP

#include <string>
#include <optional>

struct CLIOptions {
    std::string inputPath;
    std::optional<std::string> outputPath;
    bool showInfo = false;
    std::optional<std::pair<int, int>> resizeDimensions;
    std::optional<std::string> convertFormat;
};

class CLI {
    public:
        static CLIOptions parse(int argc, char* argv[]);
};


#endif // CLI_HPP