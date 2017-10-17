#ifndef DEBUGLINE_H
#define DEBUGLINE_H

#include <string>

namespace engine {

    // The DebugLine is a wrapper for a console message.
    // Very simple, but necessary for planned features
    // such as runtime construction of more complex
    // messages with variables.

    typedef unsigned int uint;
    class DebugLine
    {
    public:
        DebugLine(std::string str);

        inline std::string set(std::string str) { string_ = str; }
        inline std::string get() const { return string_; }
    private:    
        uint timestamp_;
        std::string string_;
    };
}

#endif