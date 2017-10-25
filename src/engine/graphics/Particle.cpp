#include "Particle.h"

#include <algorithm>

namespace engine { namespace graphics {
    void Particle::applyForce(Force force, float dt)
    {
        addVelocity(force.newtons/mass, dt); 
    }

    void Particle::push(sf::Vector2f mpos)
    {
        sf::Vector2f R = mpos - position;
        float r = common::math::abs(R);
        addVelocity(-(1000.f/(r*r*mass))*R);
    }

    void Particle::update(float dt, sf::Vector2f mpos)
    {
        sf::Vector2f R = mpos - position;
        float r = common::math::abs(R);
        addVelocity((1500.f/(r*r*mass))*R, dt);
        addVelocity(-0.05f*velocity*common::math::abs(velocity), dt);
        angle += dt*angularMomentum;
        position += dt*velocity;
        float absVel = common::math::abs(velocity) * 10.f;
        vertices[0].position = position + scale*common::math::rotate(points[0], angle);
        vertices[1].position = position + scale*common::math::rotate(points[1], angle);
        vertices[2].position = position + scale*common::math::rotate(points[2], angle);
        vertices[3].position = position + scale*common::math::rotate(points[3], angle);
        int color = std::min<int>(255, static_cast<int>(128/scale));
        vertices[0].color = sf::Color(color, color, color);
        vertices[1].color = sf::Color(color, color, color);
        vertices[2].color = sf::Color(color, color, color);
        vertices[3].color = sf::Color(color, color, color);
    }
}}