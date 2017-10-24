#include "ParticleArray.h"

namespace engine { namespace graphics {
    ParticleArray::ParticleArray()
    {
        varr.setPrimitiveType(sf::PrimitiveType::Triangles);
        varr.resize(3*numParticles);
        particles.resize(numParticles);
        Particle p;
        for (int i = 0; i < numParticles; i++)
        {
            p.pos = sf::Vector2f(400.f*engine::random::randFloat(),
                                 400.f*engine::random::randFloat());
            float x = 2*(engine::random::randFloat() - 0.5);
            float r = 0.5 + engine::random::randFloat();
            p.dir = r*8.f*sf::Vector2f(x, sqrt(1 - x*x));
            particles[i] = p;
        }
    }

    void ParticleArray::update()
    {
        for (int i = 0; i < numParticles; i++)
        {
            particles[i].dir = sf::Vector2f(0.9999f*particles[i].dir.x - 0.0087f*particles[i].dir.y,
                                            0.0087f*particles[i].dir.x + 0.9999f*particles[i].dir.y);
        }

        for (int i = 0; i < numParticles; i++)
        {
            sf::Vector2f pos = particles[i].pos;
            sf::Vector2f dir = particles[i].dir;
            varr[3*i] = sf::Vertex(pos + 2.f*dir);
            varr[3*i + 1] = sf::Vertex(pos + sf::Vector2f(-0.5f*dir.x - 0.866f*dir.y, 0.866f*dir.x - 0.5f*dir.y), sf::Color(0, 0, 0));
            varr[3*i + 2] = sf::Vertex(pos + sf::Vector2f(-0.5f*dir.x + 0.866f*dir.y, -0.866f*dir.x - 0.5f*dir.y), sf::Color(0, 0, 0));
        }
    }

    void ParticleArray::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(varr);
    }
}}