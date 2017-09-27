#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace engine {
namespace graphics {

    class Tilemap : public sf::Drawable, public sf::Transformable
    {
    public:
        void setSize(int u, int v);
        void setTileSize(sf::Vector2f& size);
        void allocateVertices();
        //void setTexture(sf::Texture& tex);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        int usize;
        int vsize;

        sf::Vector2f tileSize;

        sf::Texture* texturePtr;
        sf::VertexArray varr;
    };

}
}