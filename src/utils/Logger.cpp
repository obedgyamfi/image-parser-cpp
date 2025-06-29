#include "utils/Logger.hpp"
#include <iostream>

void Logger::log(const std::string& message, LogLevel level) {
	switch (level) {
		case LogLevel::Info :
			std::cout << "[INFO] " << message << std::endl;
			break;
		case LogLevel::Warning : 
			std::cout << "[WARNING] " << message << std::endl;
			break;
		case LogLevel::Error : 
			std::cerr << "[ERROR] " << message << std::endl;
			break;
	}
}

void Logger::info(const std::string& message) {
	log(message, LogLevel::Info);
}

void Logger::warning(const std::string& message) {
	log(message, LogLevel::Warning);
}

void Logger::error(const std::string& message) {
	log(message, LogLevel::Error);
}