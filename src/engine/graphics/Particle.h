#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"
#include "engine/graphics/PointParticle.h"
#include "common/math/VectorHelpers.h"


namespace engine { namespace graphics {
    class Particle : public PointParticle
    {
    public:
        inline void setScale(float s) { scale = s; }
        inline void addScale(float s, float dt = 1.f) { scale += s * dt;}
        
        inline void setAngle(float a) { angle = a; }
        inline void setAngularMomentum(float a) { angularMomentum = a; }
        inline void setAngularDragFactor(float drag) { angularDragFactor = drag; }

        inline void addAngle(float a, float dt = 1.f) { angle += dt*a; }
        inline void addAngularMomentum(float a, float dt = 1.f) { angularMomentum += dt*a; } 

        void applyForce(sf::Vector2f force, float dt = 1.f); 

        virtual void timeStep(float dt);
        virtual void updateVertices();
    private:
        float angle = 0.f;
        float angularMomentum = 0.f;
        float angularDragFactor = 0.f;
        float scale = 1.f;
        sf::Vector2f points[4] = { 0.5f*sf::Vector2f(-1.f, -1.f),
                                   0.5f*sf::Vector2f(1.f, -1.f),
                                   0.5f*sf::Vector2f(1.f, 1.f),
                                   0.5f*sf::Vector2f(-1.f, 1.f)};
    };
}}

#endif