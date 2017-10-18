#ifndef LUAHELPERS_H
#define LUAHELPERS_H

#include <string>

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"

#include "SFML/Graphics.hpp"

namespace engine { namespace lua {
    sf::Vector2f getVector2f(sel::Selector selector);
}}

#endif