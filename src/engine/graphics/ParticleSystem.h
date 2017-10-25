#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <math.h>
#include <vector>

#include "SFML/Graphics.hpp"

#include "engine/graphics/Particle.h"
#include "engine/random/Random.h"
#include "engine/input/Mouse.h"


namespace engine { namespace graphics {
    class ParticleSystem : public sf::Drawable, public sf::Transformable
    {
    public:
        void setupTestSystem();
        void setNumParticles(int num);
        void init();
        void update(float dt);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        std::vector<Particle> particles;
        int numParticles;
        sf::VertexArray varr;

    };
}}

#endif