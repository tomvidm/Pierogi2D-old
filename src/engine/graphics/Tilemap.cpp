#include "Tilemap.h"

namespace engine {
namespace graphics {
    Tilemap::Tilemap()
    {
        ;
    }

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
                setTilePlacement(u, v);
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

    // NOT CORRECT
    void Tilemap::allocateVerticesOrdered()
    {
        varr.setPrimitiveType(sf::PrimitiveType::Quads);
        varr.resize(4 * (usize * vsize));

        grid.setPrimitiveType(sf::PrimitiveType::Lines);
        grid.resize(2 * (usize + vsize + 2));

        for (int n = 0; n <= usize + vsize; n++)
        {
            for (int i = 0; i < n; i++)
            {
                setTilePlacement(i, n - i);
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

    void Tilemap::setTilePlacement(int u, int v)
    {
        sf::Vertex* quad = getQuad(u, v);
        float uf = static_cast<float>(u);
        float vf = static_cast<float>(v);
        quad[0].position = uf*uVector + vf*vVector;
        quad[1].position = (uf + 1.f)*uVector + vf*vVector;
        quad[2].position = (uf + 1.f)*uVector + (vf + 1)*vVector;
        quad[3].position = uf*uVector + (vf + 1)*vVector;
        setTextureToTile(u, v, sf::Vector2f(10*32, 0*32), sf::Vector2f(32, 32));
    }

    void Tilemap::setTextureHandler(TextureHandler& texHandler)
    {
        textureHandlerPtr = &texHandler;
    }

    void Tilemap::setTexture(std::string texture)
    {
        texturePtr = &textureHandlerPtr->get(texture);
    }

    void Tilemap::setTextureToTile(int u, int v, sf::Vector2f position, sf::Vector2f size)
    {
        if (u < 0 || u >= usize || v < 0 || v >= vsize) return;
        sf::Vertex* quad = getQuad(u, v);
        quad[0].texCoords = position;
        quad[1].texCoords = position + sf::Vector2f(size.x, 0);
        quad[2].texCoords = position + size;
        quad[3].texCoords = position + sf::Vector2f(0, size.y);
    }

    void Tilemap::update()
    {
        ;
    }

    void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        // states.texture = &m_tileset;

        // draw the vertex array
        target.draw(varr, sf::RenderStates(states.blendMode, states.transform, texturePtr, states.shader));
        if (showGrid) target.draw(grid, states);
    }

    sf::Vector2i Tilemap::getMouseOverVector() const
    {
        sf::Vector2f relativeMousePos = engine::input::Mouse::getMouseFloatPos() - getPosition();
        float xpos = relativeMousePos.x;
        float ypos = relativeMousePos.y;
        float upos = xpos/2 + ypos;
        float vpos = -xpos/2 + ypos;
        return sf::Vector2i(static_cast<int>(floor(upos/32.f)),
                            static_cast<int>(floor(vpos/32.f)));
    }

    sf::Vertex* Tilemap::getQuad(int u, int v)
    {
        return &varr[4*(usize*v + u)];
    }

    void Tilemap::setDefaultColor(int u, int v)
    {
        if (u < 0 || u >= usize || v < 0 || v >= vsize) return;
        sf::Vertex* quad = getQuad(u, v);
        quad[0].color = sf::Color(128, 128, 128);
        quad[1].color = sf::Color(192, 128, 128);
        quad[2].color = sf::Color(128, 192, 128);
        quad[3].color = sf::Color(128, 128, 192);
    }
}
}