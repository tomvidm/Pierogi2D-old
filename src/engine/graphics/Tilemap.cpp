#include "Tilemap.h"

namespace engine {
namespace graphics {
    void Tilemap::setSize(int u, int v)
    {
        usize = u;
        vsize = v;
        allocateVertices();
    }

    void Tilemap::setTileSize(sf::Vector2f& size)
    {
        tileSize = size;
    }

    void Tilemap::allocateVertices()
    {
        varr.setPrimitiveType(sf::PrimitiveType::Quads);
        varr.resize(4 * (usize * vsize));

        for (int u = 0; u < usize; u++)
        {
            for (int v = 0; v < vsize; v++)
            {
                float half_border_size = 2.f;
                sf::Vertex* quad = &varr[4*(usize*u + v)];
                quad[0].position = sf::Vector2f(u*tileSize.x + half_border_size, v*tileSize.y + half_border_size);
                quad[1].position = sf::Vector2f(u*tileSize.x + half_border_size, (v + 1)*tileSize.y - half_border_size);
                quad[2].position = sf::Vector2f((u + 1)*tileSize.x - half_border_size, (v + 1)*tileSize.y - half_border_size);
                quad[3].position = sf::Vector2f((u + 1)*tileSize.x - half_border_size, v*tileSize.y + half_border_size);
            }
        }
    }

    void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        // states.texture = &m_tileset;

        // draw the vertex array
        target.draw(varr, states);
    }
}
}