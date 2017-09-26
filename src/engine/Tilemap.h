#include "SFML/Graphics.hpp"

namespace engine {
namespace graphics {

    class Tilemap
    {
    public:
        Tilemap();
        void allocateVertices();
        void setTexture(sf::Texture& tex);
    private:
        int u, v;
        sf::Texture* texturePtr;
        sf::VertexArray varr;
    };

}
}