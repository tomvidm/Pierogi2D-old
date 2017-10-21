#ifndef PARTICLEARRAY_H
#define PARTICLEARRAY_H

#include "SFML/Graphics.hpp"

#include "engine/random/Random.h"

namespace engine { namespace graphics {
	struct Particle
	{

	}
	
	class ParticleArray
	{
	public:

	private:
		sf::VertexArray varr;

		int numParticles;
	}
}}

#endif