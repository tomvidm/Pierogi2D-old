#ifndef POINTPARTICLE_H
#define POINTPARTICLE_H

#include <math.h>
#include <algorithm>

#include "SFML/Graphics.hpp"

#include "engine/random/Random.h"
#include "common/math/VectorHelpers.h"

namespace engine { namespace graphics {
	class PointParticle
	{
	public:
  		inline void setMass(float m) { mass = m; }

  		inline void setPosition(sf::Vector2f pos) { position = pos; }
      inline void setVelocity(sf::Vector2f vel) { velocity = vel; }

      inline void addPosition(sf::Vector2f p, float dt = 1.f) { position += dt*p; }
      inline void addVelocity(sf::Vector2f v, float  dt = 1.f) { velocity += dt*v; }

      void applyForce(sf::Vector2f forc, float dt);

      virtual void setVertexIndex(sf::Vertex* vertexPtr);
      virtual void timeStep(float dt);
      virtual void updateVertices();

      inline sf::Vector2f getPosition() const { return position; }
 	protected:
   		float mass = 1.f;

   		sf::Vector2f position = sf::Vector2f(0.f, 0.f);
   		sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);

   		sf::Vertex* vertexIndex = nullptr;
	};
}}

#endif