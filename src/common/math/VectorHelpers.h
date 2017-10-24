#ifndef VECTORHELPERS_H
#define VECTORHELPERS_H

#include <math.h>

#include "SFML/Graphics.hpp"

namespace common { namespace math {
    float abs(sf::Vector2f vec);
    sf::Vector2f normalize(sf::Vector2f vec);
}}


#endif