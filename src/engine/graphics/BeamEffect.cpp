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

    void BeamEffect::setThickness(float t)
    {
        thickness = t;
    }

    void BeamEffect::updateVertices(float t)
    {
        sf::Vector2f mainDir = endPos - startPos;
        sf::Vector2f mainNormal = common::math::normalize(sf::Vector2f(-mainDir.y, mainDir.x));

        sf::Vector2f dir;
        sf::Vector2f bridge;
        sf::Vector2f midNormal;

        for (int i = 0; i < numPoints_; i++)
        {
            float s = static_cast<float>(i)/static_cast<float>(numPoints_ - 1);
            points[i] = startPos + mainDir * s + 24.f * func(s, 0.2*getSeconds()) * mainNormal;
        }

        for (int i = 1; i < numPoints_ - 1; i++)
        {
            float s = static_cast<float>(i)/static_cast<float>(numPoints_ - 1);
            bridge = points[i + 1] - points[i - 1];
            midNormal = common::math::normalize(sf::Vector2f(-bridge.y, bridge.x));
            
            beamVertices[2*i] = sf::Vertex(points[i] + 0.5f*thickness*midNormal, sf::Vector2f(266.f, 12.f));
            beamVertices[2*i + 1] = sf::Vertex(points[i] - 0.5f*thickness*midNormal, sf::Vector2f(353.f, 12.f));
            beamLines[2*i] = sf::Vertex(points[i] + 0.5f*thickness*midNormal, sf::Color::Blue);
            beamLines[2*i + 1] = sf::Vertex(points[i] - 0.5f*thickness*midNormal, sf::Color::Red);
        }

        beamVertices[0] = sf::Vertex(startPos + 0.5f*thickness*mainNormal, sf::Vector2f(266.f, 12.f));
        beamVertices[1] = sf::Vertex(startPos - 0.5f*thickness*mainNormal, sf::Vector2f(353.f, 12.f));
        beamVertices[2*numPoints_ - 2] = sf::Vertex(endPos + 0.5f*thickness*mainNormal, sf::Vector2f(266.f, 12.f));
        beamVertices[2*numPoints_ - 1] = sf::Vertex(endPos - 0.5f*thickness*mainNormal, sf::Vector2f(353.f, 12.f));
        beamLines[0] = sf::Vertex(startPos + 0.5f*thickness*mainNormal, sf::Color::Blue);
        beamLines[1] = sf::Vertex(startPos - 0.5f*thickness*mainNormal, sf::Color::Red);
        beamLines[2*numPoints_ - 2] = sf::Vertex(endPos + 0.5f*thickness*mainNormal, sf::Color::Blue);
        beamLines[2*numPoints_ - 1] = sf::Vertex(endPos - 0.5f*thickness*mainNormal, sf::Color::Red);
    }

    void BeamEffect::update()
    {
        updateVertices();
    }

    float BeamEffect::func(float s, float t)
    {
        float r = static_cast<float>(sin(3.1415*s));
        float k = static_cast<float>(sin(5*3.1415*(s - t)));
        return r*k;
    }

    void BeamEffect::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(beamVertices, sf::RenderStates(beamTexturePtr));
        target.draw(beamLines);
    }
}}