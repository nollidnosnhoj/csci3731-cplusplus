#include "Log.h"
#include <string>
#include <iostream>

Log::Log() {
    this->isLogging = false;
}

Log::~Log() {
    
}

// generate singleton instance
const Log& Log::getInstance() {
    static Log instance;
    return instance;
}

void Log::print(const std::string& content) const {
    std::cout << "Log: " << content << std::endl;
}

void Log::LoggingActive(bool turn) const {
    if (isLogging != turn) {
        isLogging = turn;
    }
}