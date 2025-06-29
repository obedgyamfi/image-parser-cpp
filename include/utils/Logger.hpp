#ifndef LOGGER_HPP
#define LOGGER_HPP 

#include <string>

enum class LogLevel {
	Info, 
	Warning, 
	Error
};

class Logger {
public: 
	void static log(const std::string& message, LogLevel level = LogLevel::Info);
	void static info(const std::string& message);
	void static warning(const std::string& message);
	void static error(const std::string& message);
};

#endif LOGGER_HPP