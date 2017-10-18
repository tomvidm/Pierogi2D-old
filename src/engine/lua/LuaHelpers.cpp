#include "LuaHelpers.h"

namespace engine { namespace lua {
    // The selector must be such that selector[1] gives the first component.
    sf::Vector2f getVector2f(sel::Selector selector)
    {
        return sf::Vector2f(selector[1], selector[2]);
    }
}}