#include "VectorHelpers.h"

namespace common { namespace math {
    float abs(sf::Vector2f vec)
    {
        return sqrt(vec.x*vec.x + vec.y*vec.y);
    }

    sf::Vector2f normalize(sf::Vector2f vec)
    {
        return vec*(1/abs(vec));
    }
}}
