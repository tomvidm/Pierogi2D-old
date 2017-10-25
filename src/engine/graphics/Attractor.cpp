#include "Attractor.h"

namespace engine { namespace graphics {
	Attractor::Attractor(float magnitude, sf::Vector2f source)
	: magnitude(magnitude), source(source)
	{
		;
	}

	sf::Vector2f Attractor::getForce(sf::Vector2f attractee) const
	{
		sf::Vector2f dir = (attractee - source);
		float absDir = common::math::abs(dir);
		if (absDir < 1.f)
		{
			return (magnitude / (1.f)) * dir;
		}
		else 
		{
			return (magnitude / (absDir * absDir)) * common::math::normalize(dir);
		}
	}
}}