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

        grid.setPrimitiveType(sf::PrimitiveType::Lines);
        grid.resize(2 * (usize + vsize + 2));

        for (int u = 0; u < usize; u++)
        {
            for (int v = 0; v < vsize; v++)
            {
                setTilePlacement(u, v, &varr[4*(usize*v + u)]);
            }
        }

        for (int n = 0; n < usize + 1; n++)
        {
            float nf = static_cast<float>(n);
            grid[2*n].position = nf*uVector;
            grid[2*n].color = sf::Color::Black;
            grid[2*n + 1].position = nf*uVector + (static_cast<float>(vsize))*vVector;
            grid[2*n + 1].color = sf::Color::Black;
        }

        for (int n = 0; n < usize + 1; n++)
        {
            float nf = static_cast<float>(n);
            grid[2*usize + 2*n].position = nf*vVector;
            grid[2*usize + 2*n].color = sf::Color::Black;
            grid[2*usize + 2*n + 1].position = nf*vVector + (static_cast<float>(usize))*uVector;
            grid[2*usize + 2*n + 1].color = sf::Color::Black;
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

    sf::Vector2i getScreenToWorldSpace(sf::Vector2i pos) const
    {
        return sf::Vector2i(0, 0);
    }

    void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        // states.texture = &m_tileset;

        // draw the vertex array
        target.draw(varr, states);
        target.draw(grid, states);
    }
}
}