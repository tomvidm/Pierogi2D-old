#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include <string>

#include "engine/console/ValueField.h"

namespace engine { namespace console {
    enum LogLevel
    {
        VERBOSE = 0,
        DEBUG,
        WARNING,
        ERROR,
        FATAL
    };

    std::string logLevelToString(LogLevel logLevel);

    class Logger
    {
    public:
        static Logger* getInstancePtr();
        void log(std::string string, LogLevel logLevel = LogLevel::VERBOSE);
        void log(std::vector<ValueField> valueFields, LogLevel logLevel = LogLevel::VERBOSE);
        void setLogLevel(LogLevel logLevel);
    protected:
        Logger();
        //Logger(const Logger& copy);
        ~Logger();
    private:
        int minLogLevel = 0;
        static Logger* instancePtr;
    };
}}

#endif