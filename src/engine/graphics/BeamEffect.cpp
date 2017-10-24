#include "BeamEffect.h"

namespace engine { namespace graphics {
    BeamEffect::BeamEffect()
    {
        lineVertices.setPrimitiveType(sf::PrimitiveType::LineStrip);
        beamVertices.setPrimitiveType(sf::PrimitiveType::TriangleStrip);
        beamLines.setPrimitiveType(sf::PrimitiveType::LineStrip);

        beamTexturePtr = engine::graphics::TextureManager::getInstancePtr()->loadFromFile("laser");
    }

    void BeamEffect::setEndpoints(sf::Vector2f start, sf::Vector2f end)
    {
        startPos = start;
        endPos = end;
    }

    void BeamEffect::setNumVertices(int numVertices) 
    {
        numVertices_ = numVertices; 
        lineVertices.resize(numVertices_); 
        beamVertices.resize(2*numVertices_);
        beamLines.resize(2*numVertices_);
        initVertices();
    }

    void BeamEffect::initVertices()
    {
        sf::Vector2f dir = endPos - startPos;

        for (int i = 0; i < numVertices_; i++)
        {
            sf::Vector2f pos = startPos + dir * (static_cast<float>(i)/static_cast<float>(numVertices_));
            lineVertices[i] = sf::Vertex(pos);

            sf::Vector2f normal = 16.f*sf::Transform().rotate(90).transformPoint(common::math::normalize(dir));
            beamVertices[2*i] = sf::Vertex(pos + normal, sf::Vector2f(266.f, 12.f));
            beamVertices[2*i + 1] = sf::Vertex(pos - normal, sf::Vector2f(353.f, 12.f));
            beamLines[2*i] = sf::Vertex(pos + normal, sf::Color::Blue);
            beamLines[2*i + 1] = sf::Vertex(pos - normal, sf::Color::Red);
        }
    }

    void BeamEffect::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(beamVertices, sf::RenderStates(beamTexturePtr));
        target.draw(lineVertices);
        target.draw(beamLines);
    }
}}