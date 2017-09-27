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
        const sf::Vector2f uVector = 32.f*sf::Vector2f(1.f, 0.5f);
        const sf::Vector2f vVector = 32.f*sf::Vector2f(-1.f, 0.5f);

        sf::Vector2f tileSize;

        sf::Texture* texturePtr;
        sf::VertexArray varr;
    };

}
}