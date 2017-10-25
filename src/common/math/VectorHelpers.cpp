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

    sf::Vector2f rotate(sf::Vector2f vec, float angle, bool radians)
    {
    	if (radians)
    	{
    		return sf::Vector2f(vec.x * cos(angle) - vec.y * sin(angle),
    							vec.x * sin(angle) + vec.y * cos(angle));
    	}
    	else
    	{
    		angle = pi*angle/180.f;
    		return sf::Vector2f(vec.x * cos(angle) - vec.y * sin(angle),
    							vec.x * sin(angle) + vec.y * cos(angle));
    	}
    	
    }
}}
