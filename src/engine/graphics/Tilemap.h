#include "SFML/Graphics.hpp"

namespace engine {
namespace graphics {

    class Tilemap : public sf::Drawable, public sf::Transformable
    {
    public:
        Tilemap();
        
        void setSize(int u, int v);
        void allocateVertices();
        void setTexture(sf::Texture& tex);
    private:
        int usize, vsize;

        sf::Vector2f tileSize;

        sf::Texture* texturePtr;
        sf::VertexArray varr;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    };

}
}