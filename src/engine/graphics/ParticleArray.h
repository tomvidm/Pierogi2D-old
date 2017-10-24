#ifndef PARTICLEARRAY_H
#define PARTICLEARRAY_H

#include <math.h>

#include "SFML/Graphics.hpp"

#include "engine/random/Random.h"

namespace engine { namespace graphics {
	struct Particle
	{
		sf::Vector2f pos;
		sf::Vector2f dir;
	};
	
	class ParticleArray : public sf::Drawable, public sf::Transformable
	{
	public:
		ParticleArray();
		void update();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		sf::VertexArray varr;
		std::vector<Particle> particles;

		int numParticles = 50;
	};
}}

#endif