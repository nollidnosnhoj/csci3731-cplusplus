#ifndef LOG_H
#define LOG_H
#include <string>

class Log {
    private:
        Log();
        std::string fileName;
        mutable bool isLogging;
    public:
        static const Log& getInstance();
        void print(const std::string& content) const;
        void LoggingActive(bool turn) const;
};

#endif