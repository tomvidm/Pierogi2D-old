#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"
#include "engine/graphics/Force.h"
#include "common/math/VectorHelpers.h"


namespace engine { namespace graphics {
    class Particle
    {
    public:
        inline void setMass(float m) { mass = m; }
        inline void setScale(float s) { scale = s; }
        
        inline void setAngle(float a) { angle = a; }
        inline void setAngularMomentum(float a) { angularMomentum = a; }
        inline void setPosition(sf::Vector2f pos) { position = pos; }
        inline void setVelocity(sf::Vector2f vel) { velocity = vel; }

        inline void addAngle(float a, float dt = 1.f) { angle += dt*a; }
        inline void addAngularMomentum(float a, float dt = 1.f) { angularMomentum += dt*a; }
        inline void addPosition(sf::Vector2f p, float dt = 1.f) { position += dt*p; }
        inline void addVelocity(sf::Vector2f v, float  dt = 1.f) { velocity += dt*v; }

        inline void setVertexStart(sf::Vertex* v) { vertices = v; }    

        void applyForce(Force force, float dt = 1.f); 
        void update(float dt, sf::Vector2f mpos);
    private:
        float mass = 1;
        float angle = 0;
        float angularMomentum = 0;
        float scale = 2.f;
        sf::Vector2f position = sf::Vector2f(0.f, 0.f);
        sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
        sf::Vector2f points[4] = { 0.5f*sf::Vector2f(-1.f, -1.f),
                                   0.5f*sf::Vector2f(1.f, -1.f),
                                   0.5f*sf::Vector2f(1.f, 1.f),
                                   0.5f*sf::Vector2f(-1.f, 1.f)};
        sf::Vertex* vertices = nullptr;
    };
}}

#endif