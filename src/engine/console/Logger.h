#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include <string>

#include "engine/console/ValueField.h"

namespace engine { namespace console {
    class Logger
    {
    public:
        static Logger* getInstancePtr();

        void log(std::string string);
        void log(std::vector<ValueField> valueFields);
    protected:
        Logger();
        //Logger(const Logger& copy);
        ~Logger();
    private:
        static Logger* instancePtr;
    };
}}

#endif