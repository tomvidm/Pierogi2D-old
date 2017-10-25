#ifndef FORCE_H
#define FORCE_H

#include <algorithm>

#include "SFML/Graphics.hpp"

#include "common/math/VectorHelpers.h"

namespace engine { namespace graphics {
    class Attractor
    {
    public:
    	Attractor(float magnitude, sf::Vector2f source);
    	inline void setMagnitude(float newMagnitude) { magnitude = newMagnitude; }
    	inline void setSource(sf::Vector2f newSource) { source = newSource; }
    	sf::Vector2f getForce(sf::Vector2f attractee) const;
    private:
    	float magnitude = 0;
        sf::Vector2f source;
    };
}}

#endif