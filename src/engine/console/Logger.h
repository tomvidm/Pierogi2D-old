#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include <string>

#include "engine/console/ValueField.h"

namespace engine { namespace console {
    enum LogLevel
    {
        DEBUG = 0,
        WARNING,
        ERROR,
        FATAL
    };

    class Logger
    {
    public:
        static Logger* getInstancePtr();
        void log(std::string string, LogLevel logLevel = LogLevel::DEBUG);
        void log(std::vector<ValueField> valueFields, LogLevel logLevel = LogLevel::DEBUG);
    protected:
        Logger();
        //Logger(const Logger& copy);
        ~Logger();
    private:
        static Logger* instancePtr;
    };
}}

#endif