#include "Tilemap.h"

namespace engine {
namespace graphics {
    Tilemap::Tilemap()
    {
        varr.setPrimitiveType(sf::PrimitiveType::Quads)
    }

    void setSize(int u, int v)
    (
        usize = u;
        vsize = v;

        allocateVertices();
    )

    void allocateVertices()
    {
        varr.resize(usize * vsize);

        for (int u = 0; u < usize; u++)
        {
            for (int v = 0; v < vsize; v++)
            {
                Vertex* quad = &varr[4*(usize*u + v)];
                quad[0].position = sf::Vector2f(u*tileSize.x, v*tileSize.y);
                quad[1].position = sf::Vector2f(u*tileSize.x, (v + 1)*tileSize.y);
                quad[2].position = sf::Vector2f((u + 1)*tileSize.x, (v + 1)*tileSize.y);
                quad[3].position = sf::Vector2f((u + 1)*tileSize.x, v*tileSize.y);
            }
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
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