#ifndef LUAHELPERS_H
#define LUAHELPERS_H

#include <string>

#include "SFML/Graphics.hpp"

#include "engine/lua/LuaIncludes.h"

namespace engine { namespace lua {
    sf::Vector2f getVector2f(sel::Selector selector);
}}

#endif