#include "ParticleSystem.h"

namespace engine { namespace graphics {
    void ParticleSystem::setupTestSystem()
    {
        setNumParticles(8000);
        varr.setPrimitiveType(sf::PrimitiveType::Quads);
        for (int i = 0; i < numParticles; i++)
        {
            float r = 3.1415f*2.f*engine::random::randFloat();
            float R = 150.f*engine::random::randFloat();
            float m = 1.f + 2*engine::random::randFloat();
            particles[i].setMass(m);
            particles[i].setScale(m);
            particles[i].setPosition(R*sf::Vector2f(cos(r), sin(r)));
        }
    }

    void ParticleSystem::setNumParticles(int num)
    {
        particles.resize(num);
        varr.resize(4*num);
        numParticles = num;
        init();
    }

    void ParticleSystem::init()
    {
        for (int i = 0; i < numParticles; i++)
        {
            particles[i].setVertexStart(&varr[4*i]);
        }
    }

    void ParticleSystem::update(float dt)
    {
        sf::Vector2f mpos = engine::input::Mouse::getMouseFloatPos();
        for (int i = 0; i < numParticles; i++)
        {
            particles[i].update(dt, mpos);
        }
    }

    void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(varr);
    }
}}