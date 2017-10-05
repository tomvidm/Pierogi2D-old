#pragma once

#include <string>

namespace engine {

    // Should be modified to be able to let one
    // or more values within a line point to some data
    // for realtime updates. This class should be used
    // by both realtime debug output and console lines.

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