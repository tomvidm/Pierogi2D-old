#ifndef DEBUGLINE_H
#define DEBUGLINE_H

#include <string>

namespace engine { namespace console {

    // The DebugLine is a wrapper for a console message.
    // Very simple, but necessary for planned features
    // such as runtime construction of more complex
    // messages with variables.

    typedef unsigned int uint;

    class DebugLine
    {
    public:
        DebugLine(std::string str);

        virtual void set(std::string str);
        virtual std::string get() const;
    protected:    
        uint timestamp_;
        std::string string_;
    };
}}

#endif