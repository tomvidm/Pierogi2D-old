#include "DebugLine.h"

namespace engine { namespace console {
    DebugLine::DebugLine()
    {
        ;
    }

    DebugLine::DebugLine(std::string str)
    {
        fields.push_back(ValueField(str));
    }

    void DebugLine::set(std::string str)
    {
        fields.push_back(ValueField(str));
    }

    void DebugLine::addField(ValueField& field)
    {
        fields.push_back(field);
    }

    std::string DebugLine::get() const 
    {
        std::string result = "";
        for (auto v : fields)
        {
            result = result + v.get();
        }
        return result;
    }
}}