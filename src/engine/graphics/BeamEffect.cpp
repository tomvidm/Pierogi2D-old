#include "BeamEffect.h"

namespace engine { namespace graphics {
    BeamEffect::BeamEffect()
    {
        clock.restart();
        beamVertices.setPrimitiveType(sf::PrimitiveType::TriangleStrip);
        beamLines.setPrimitiveType(sf::PrimitiveType::LineStrip);

        beamTexturePtr = engine::graphics::TextureManager::getInstancePtr()->loadFromFile("laser");
    }

    void BeamEffect::setEndpoints(sf::Vector2f start, sf::Vector2f end)
    {
        startPos = start;
        endPos = end;
    }

    void BeamEffect::setNumVertices(int numPoints) 
    {
        numPoints_ = numPoints; 
        points.resize(numPoints_); 
        beamVertices.resize(2*numPoints_);
        beamLines.resize(2*numPoints_);
        updateVertices();
    }

    void BeamEffect::updateVertices(float t)
    {
        sf::Vector2f mainDir = endPos - startPos;
        sf::Vector2f dir;
        sf::Vector2f prevPos = startPos;
        sf::Vector2f newPos;
        sf::Vector2f normal;

        beamVertices[0] = sf::Vertex(newPos + normal, sf::Vector2f(266.f, 12.f));
        beamVertices[1] = sf::Vertex(newPos - normal, sf::Vector2f(353.f, 12.f));
        beamLines[0] = sf::Vertex(newPos + normal, sf::Color::Blue);
        beamLines[1] = sf::Vertex(newPos - normal, sf::Color::Red);

        for (int i = 1; i < numPoints_; i++)
        {
            float s = static_cast<float>(i)/static_cast<float>(numPoints_);
            newPos = startPos + mainDir * s;
            dir = common::math::normalize(newPos - prevPos);
            normal = sf::Vector2f(-dir.y, dir.x);
            
            newPos = newPos + 32.f*static_cast<float>(sin(2*3.1415*(s - 0.3*getSeconds())))*normal;

            beamVertices[2*i] = sf::Vertex(newPos + normal, sf::Vector2f(266.f, 12.f));
            beamVertices[2*i + 1] = sf::Vertex(newPos - normal, sf::Vector2f(353.f, 12.f));
            beamLines[2*i] = sf::Vertex(newPos + normal, sf::Color::Blue);
            beamLines[2*i + 1] = sf::Vertex(newPos - normal, sf::Color::Red);

            prevPos = newPos;
        }
    }

    void BeamEffect::update()
    {
        updateVertices();
    }

    void BeamEffect::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(beamVertices, sf::RenderStates(beamTexturePtr));
        target.draw(beamLines);
    }
}}