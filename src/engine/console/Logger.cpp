#include "Logger.h"

namespace engine { namespace console {
    Logger* Logger::instancePtr = nullptr;

    Logger* Logger::getInstancePtr()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new Logger;
            instancePtr->log("Logger initialized...\n");
        }

        return instancePtr;
    }

    void Logger::log(std::string string, LogLevel logLevel)
    {
        std::cout << string;
    }

    void Logger::log(std::vector<ValueField> valueFields, LogLevel logLevel)
    {
        for (auto v : valueFields)
        {
            std::cout << v.get();
        }
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