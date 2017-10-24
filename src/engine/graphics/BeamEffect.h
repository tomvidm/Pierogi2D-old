#ifndef BEAMEFFECT_H
#define BEAMEFFECT_H

#include <math.h>

#include "SFML/Graphics.hpp"

#include "common/math/VectorHelpers.h"
#include "engine/console/Logger.h"
#include "engine/graphics/TextureManager.h"

namespace engine { namespace graphics {


    class BeamEffect : public sf::Drawable, public sf::Transformable
    {
    public:
        BeamEffect();
        void setEndpoints(sf::Vector2f start, sf::Vector2f end);

        void setNumVertices(int numVertices);

        void updateVertices(float t = 0.f);

        void update();

        inline float getSeconds() const { return clock.getElapsedTime().asSeconds(); }

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2f startPos;
        sf::Vector2f endPos;
        std::vector<sf::Vector2f> points;
        sf::VertexArray beamVertices;
        sf::VertexArray beamLines;

        sf::Texture* beamTexturePtr;

        int numPoints_;
        sf::Clock clock;
    };
}}

#endif