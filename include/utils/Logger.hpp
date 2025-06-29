#ifdef LOGGER_HPP
#define LOGGER_HPP

#include <string>

enum class LogLevel {
    Info, 
    Warning,
    Error
};

class Logger {
    public:
        static void log(const std::string& message, LogLevel level = LogLevel::Info);

        static void info(const std::string& message);
        static void warning(const std::string& message);
        static void error(const std:::string& message);
};

#endif // LOGGER_HPP