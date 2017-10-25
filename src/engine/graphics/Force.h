#ifndef FORCE_H
#define FORCE_H

#include "SFML/Graphics.hpp"

namespace engine { namespace graphics {
    struct Force
    {
        sf::Vector2f newtons;
        sf::Vector2f source;
    };
}}

#endif