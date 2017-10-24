#include "Logger.h"

namespace engine { namespace console {
    Logger* Logger::instancePtr = nullptr;

    std::string logLevelToString(LogLevel logLevel)
    {
        switch(logLevel)
        {
            case VERBOSE:
                return "VERBOSE\t- ";
            case DEBUG:
                return "DEBUG\t- ";
            case WARNING:
                return "WARNING\t- ";
            case ERROR:
                return "ERROR\t- ";
            case FATAL:
                return "FATAL\t- ";
            default:
                return "log!?!?\t- ";
        }
    }

    Logger* Logger::getInstancePtr()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new Logger;
            instancePtr->log("Logger initialized...\n", DEBUG);
        }

        return instancePtr;
    }

    void Logger::log(std::string string, LogLevel logLevel)
    {
        if (static_cast<int>(logLevel) >= minLogLevel)
        {
            std::cout << logLevelToString(logLevel) << string;
        }
    }

    void Logger::log(std::vector<ValueField> valueFields, LogLevel logLevel)
    {
        if (static_cast<int>(logLevel) >= minLogLevel)
        {
            std::cout << logLevelToString(logLevel);
            for (auto v : valueFields)
            {
                std::cout << v.get();
            }
        }
    }

    void Logger::setLogLevel(LogLevel logLevel)
    {
        minLogLevel = static_cast<int>(logLevel);
    }

    Logger::Logger()
    {
        ;
    }

    Logger::~Logger()
    {
        delete instancePtr;
    }
}}