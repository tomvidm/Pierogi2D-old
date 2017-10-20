#ifndef VALUEFIELD_H
#define VALUEFIELD_H

#include <string>

namespace engine { namespace console {

    enum class FieldType
    {
        INT,
        UINT,
        FLOAT,
        STRING,
        INT_PTR,
        UINT_PTR,
        FLOAT_PTR,
        STRING_PTR
    };

    typedef unsigned int uint;


    // This class contains a string and a union of 
    // different types and pointers. The purpose is to enable
    // DebugLine to have a vector of ValueFields to compose lines
    // containing different types. This allows for composing strings
    // from other strings and fixed-size values (int, double, float)
    // and from values pointed to by pointers.

    class ValueField
    {
    public:
        ValueField(int);
        ValueField(uint);
        ValueField(float);
        ValueField(std::string);
        ValueField(int*);
        ValueField(uint*);
        ValueField(float*);
        ValueField(std::string*);

        std::string get() const;
    private:
        FieldType fieldType;

        std::string string;
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