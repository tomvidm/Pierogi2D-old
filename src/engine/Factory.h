#ifndef FACTORY_H
#define FACTORY_H

#include <string>

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"

#include "Entity.h"

// The Factory class takes an ID of an object.

namespace engine {
    class EntityFactory
    {
    public:
        Entity createObject(std::string id);
    private:
        sel::State luaState;
    };
}

#endif