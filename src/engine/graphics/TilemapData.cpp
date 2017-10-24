#include "TilemapData.h"

namespace engine { namespace graphics {

    Tile::Tile()
    {
        ;
    }

    Tile::Tile(int u, int v, sf::Vertex* quad, sf::Vector2f texCoords)
    : u(u), v(v), quad(quad), texCoord(texCoord)
    {
        ;
    }

    TilemapData::TilemapData()
    {
        engine::console::Logger::getInstancePtr()->log("TilemapData initialized...\n");
    }

    void TilemapData::setSize(int u, int v)
    {
        uSize = u;
        vSize = v;
        tileVector.resize(uSize * vSize);
    }

    int TilemapData::coordsToIndex(int u, int v)
    {
        return uSize*u + v;
    }
}}