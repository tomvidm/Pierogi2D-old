#include "DebugLine.h"

namespace engine { namespace console {
    DebugLine::DebugLine(std::string str)
    : string_(str) 
    {
        ;
    }

    void DebugLine::set(std::string str)
    {
        string_ = str;
    }

    std::string DebugLine::get() const 
    {
        return string_;
    }
}}