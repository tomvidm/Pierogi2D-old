#include "ParticleSystem.h"

namespace engine { namespace graphics {
    ParticleSystem::ParticleSystem()
    {
        setParticlePrimitiveType(sf::PrimitiveType::Quads);
    }

    ParticleSystem::~ParticleSystem()
    {
        for (int i = 0; i < numParticles; i++)
        {
            delete particles[i];
        }
    }

    void ParticleSystem::setupTestSystem()
    {
        setNumParticles(2000);
        for (int i = 0; i < numParticles; i++)
        {
            float r = 2*common::math::pi * engine::random::randFloat();
            float R = engine::random::randFloat();
            particles[i]->setPosition(250.f * R * sf::Vector2f(cos(r), sin(r)));
            static_cast<Particle*>(particles[i])->setScale(5.f);
        }
    }

    void ParticleSystem::setParticlePrimitiveType(sf::PrimitiveType primitiveType)
    {
        vertexArray.setPrimitiveType(primitiveType);
        switch (primitiveType)
        {
            case sf::PrimitiveType::Points:
                numVerticesPerParticle = 1;
                break;
            case sf::PrimitiveType::Quads:
                numVerticesPerParticle = 4;
                break;
            default:
                numVerticesPerParticle = 1;
        }
    }

    void ParticleSystem::setNumParticles(int num)
    {
        numParticles = num;
        particles.resize(numParticles);
        vertexArray.resize(numVerticesPerParticle * numParticles);

        for (int i = 0; i < numParticles; i++)
        {
            if (numVerticesPerParticle == 1)
            {
                particles[i] = new PointParticle();
            }
            else
            {
                particles[i] = new Particle();
            }
        }

        init();
    }

    void ParticleSystem::setParticleLifetime(float seconds)
    {
        lifetime = seconds;
    }

    void ParticleSystem::addAttractor(Attractor attractor)
    {
        attractors.push_back(attractor);
    }

    void ParticleSystem::init()
    {
        for (int i = 0; i < numParticles; i++)
        {
            particles[i]->setVertexIndex(&vertexArray[numVerticesPerParticle * i]);
        }
    }

    void ParticleSystem::update(float dt)
    {
        if (numVerticesPerParticle == 1)
        {
            updatePointParticles(dt);
        }
        else
        {
            updateQuadParticles(dt);
        }
    }

    void ParticleSystem::updatePointParticles(float dt)
    {
        for (int i = 0; i < numParticles; i++)
        {
            for (int j = 0; j < attractors.size(); j++)
            {
                particles[i]->applyForce(attractors[j].getForce(particles[i]->getPosition()), dt);
            }
            particles[i]->timeStep(dt);
        }
    }

    void ParticleSystem::updateQuadParticles(float dt)
    {
        for (int i = 0; i < numParticles; i++)
        {
            for (int j = 0; j < attractors.size(); j++)
            {
                static_cast<Particle*>(particles[i])->applyForce(attractors[j].getForce(particles[i]->getPosition()), dt);
            }
            static_cast<Particle*>(particles[i])->timeStep(dt);
        }
    }

    void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(vertexArray);
    }
}}