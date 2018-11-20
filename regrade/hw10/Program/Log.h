#ifndef LOG_H
#define LOG_H
#include <string>

class Log {
    private:
        Log();
        virtual ~Log();
        mutable bool isLogging;
    public:
        static const Log& getInstance();
        void print(const std::string& content) const;
        void LoggingActive(bool turn) const;
};

#endif