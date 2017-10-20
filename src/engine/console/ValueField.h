#ifndef VALUEFIELD_H
#define VALUEFIELD_H

#include <string>

namespace engine { namespace console {

    enum class FieldType
    {
        INT,
        UINT,
        FLOAT,
        INT_PTR,
        UINT_PTR,
        FLOAT_PTR,
        STRING_PTR
    };

    typedef unsigned int uint;

    class ValueField
    {
    public:
        ValueField(int);
        ValueField(uint);
        ValueField(float);
        ValueField(int*);
        ValueField(uint*);
        ValueField(float*);
        ValueField(std::string*);

        std::string get() const;
    private:
        FieldType fieldType;
        union {
            int intValue;
            uint uintValue;
            float floatValue;
            int* intValuePtr;
            uint* uintValuePtr;
            float* floatValuePtr;
            std::string* stringPtr;
        };
    };
}}

#endif