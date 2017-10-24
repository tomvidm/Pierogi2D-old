#ifndef PARTICLEARRAY_H
#define PARTICLEARRAY_H

#include "SFML/Graphics.hpp"

#include "engine/random/Random.h"

namespace engine { namespace graphics {
	struct Particle
	{
		sf::Vertex vertices[3];
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