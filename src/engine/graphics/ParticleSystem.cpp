#include "ParticleSystem.h"

namespace engine { namespace graphics {
    void ParticleSystem::setupTestSystem()
    {
        setNumParticles(4200);
        texPtr = TextureManager::getInstancePtr()->loadFromFile("light");
        varr.setPrimitiveType(sf::PrimitiveType::Quads);
        for (int i = 0; i < numParticles; i++)
        {
            float r = 3.1415f*2.f*engine::random::randFloat();
            float R = 250.f*engine::random::randFloat();
            float m = 1.f*(1.f + 10.f*engine::random::randFloat());
            particles[i].setMass(m*m);
            particles[i].setScale(5.f*m);
            particles[i].setPosition(R*sf::Vector2f(cos(r), sin(r)));
            varr[4*i].texCoords = sf::Vector2f(0, 0);
            varr[4*i + 1].texCoords = sf::Vector2f(256.f, 0.f);
            varr[4*i + 2].texCoords = sf::Vector2f(256.f, 256.f);
            varr[4*i + 3].texCoords = sf::Vector2f(0, 256.f);
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

    void ParticleSystem::push()
    {
        sf::Vector2f mpos = engine::input::Mouse::getMouseFloatPos();

        for (int i = 0; i < numParticles; i++)
        {
            particles[i].push(mpos);
        }
    }

    void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states = sf::RenderStates(texPtr);
        states.blendMode = sf::BlendAdd;

        target.draw(varr, states);
    }
}}