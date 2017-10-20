#ifndef DEBUGLINE_H
#define DEBUGLINE_H

#include <vector>
#include <string>

#include "ValueField.h"

namespace engine { namespace console {

    // The DebugLine stores a vector of ValueFields
    // and has the purpose of returnin a string constructed
    // from these fields.

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