#ifndef VECTORHELPERS_H
#define VECTORHELPERS_H

#include <math.h>

#include "SFML/Graphics.hpp"
#include "common/math/Constants.h"

namespace common { namespace math {
    float abs(sf::Vector2f vec);
    sf::Vector2f normalize(sf::Vector2f vec);
    sf::Vector2f rotate(sf::Vector2f vec, float angle, bool radians = false);
}}


#endif