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
                setTilePlacement(u, v, &varr[4*(usize*v + u)]);
            }
        }
    }

    void Tilemap::setTilePlacement(int u, int v, sf::Vertex* quad)
    {
        float uf = static_cast<float>(u);
        float vf = static_cast<float>(v);
        quad[0].position = uf*uVector + vf*vVector;
        quad[1].position = (uf + 1.f)*uVector + vf*vVector;
        quad[2].position = (uf + 1.f)*uVector + (vf + 1)*vVector;
        quad[3].position = uf*uVector + (vf + 1)*vVector;
        quad[0].color = sf::Color(128, 128, 128);
        quad[1].color = sf::Color(192, 128, 128);
        quad[2].color = sf::Color(128, 192, 128);
        quad[3].color = sf::Color(128, 128, 192);
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