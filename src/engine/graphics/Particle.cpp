#include "Particle.h"

#include <algorithm>

namespace engine { namespace graphics {
    void Particle::applyForce(sf::Vector2f force, float dt)
    {
        addVelocity((1.f/mass) * force, dt);
    }

    void Particle::timeStep(float dt)
    {
        addPosition(velocity, dt);

        updateVertices();
    }

    void Particle::updateVertices()
    {
        vertexIndex[0].position = position + scale*common::math::rotate(points[0], angle);
        vertexIndex[1].position = position + scale*common::math::rotate(points[1], angle);
        vertexIndex[2].position = position + scale*common::math::rotate(points[2], angle);
        vertexIndex[3].position = position + scale*common::math::rotate(points[3], angle);
    }
}}