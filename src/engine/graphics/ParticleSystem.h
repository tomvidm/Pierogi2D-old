#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <math.h>
#include <vector>

#include "SFML/Graphics.hpp"

#include "common/math/Constants.h"
#include "engine/graphics/PointParticle.h"
#include "engine/graphics/Particle.h"
#include "engine/random/Random.h"
#include "engine/input/Mouse.h"
#include "engine/graphics/TextureManager.h"
#include "engine/graphics/Attractor.h"


namespace engine { namespace graphics {
    class ParticleSystem : public sf::Drawable, public sf::Transformable
    {
    public:
        ParticleSystem();
        ~ParticleSystem();

        void setupTestSystem();
        void setParticlePrimitiveType(sf::PrimitiveType primitiveType);
        void setNumParticles(int num);
        void setParticleLifetime(float seconds);

        void addAttractor(Attractor attractor);
        void init();
        void update(float dt);
        void updatePointParticles(float dt);
        void updateQuadParticles(float dt);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        std::vector<Attractor> attractors;
        std::vector<PointParticle*> particles;

        int numParticles;
        int numVerticesPerParticle;
        float lifetime;

        sf::VertexArray vertexArray;
    };
}}

#endif