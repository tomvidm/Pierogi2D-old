#include "PointParticle.h"

namespace engine { namespace graphics {
	void PointParticle::applyForce(sf::Vector2f force, float dt)
	{
		addVelocity((1.f/mass) * force, dt);
	}

	void PointParticle::setVertexIndex(sf::Vertex* vertexPtr)
	{
		vertexIndex = vertexPtr;
	}

	void PointParticle::timeStep(float dt)
	{
		addVelocity(-dragFactor * common::math::abs(velocity) * velocity);
		addPosition(velocity, dt);

		updateVertices();
	}

	void PointParticle::updateVertices()
	{
		vertexIndex->position = position;
	}
}}