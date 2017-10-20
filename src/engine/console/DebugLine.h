#ifndef DEBUGLINE_H
#define DEBUGLINE_H

#include <vector>
#include <string>

#include "ValueField.h"

namespace engine { namespace console {

    // The DebugLine is a wrapper for a console message.
    // Very simple, but necessary for planned features
    // such as runtime construction of more complex
    // messages with variables.

    typedef unsigned int uint;

    class DebugLine
    {
    public:
        DebugLine();
        DebugLine(std::string str);

        virtual void set(std::string str);
        virtual void addField(ValueField &field);
        virtual std::string get() const;
    protected:    
        uint timestamp_;
        std::vector<ValueField> fields;
    };
}}

#endif