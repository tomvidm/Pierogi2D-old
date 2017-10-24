#ifndef BEAMEFFECT_H
#define BEAMEFFECT_H

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

        void initVertices();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vector2f startPos;
        sf::Vector2f endPos;
        sf::VertexArray lineVertices;
        sf::VertexArray beamVertices;
        sf::VertexArray beamLines;

        sf::Texture* beamTexturePtr;

        int numVertices_;
    };
}}

#endif