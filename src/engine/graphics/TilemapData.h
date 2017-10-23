#ifndef TILEMAPDATA_H
#define TILEMAPDATA_H

#include <map>

#include "SFML/Graphics.hpp"

#include "engine/console/Logger.h"

namespace engine { namespace graphics {
    // The Tile struct holds information about a Tile.

    struct Tile
    {
        int u, v;                   // Coordinates in tilemap
        sf::Vertex* quad = nullptr; // Pointer to first vertex of quad
        sf::Vector2f texCoord;      // Position of upper left texture coordinate
    };

    class TilemapData
    {
    public:
        TilemapData();
        void setSize(int u, int v);
    private:
        int uSize;
        int vSize;
        std::vector<Tile> tileVector;

        sf::Texture* texturePtr = nullptr;
    };

    int coordsToIndex(int u, int v);

}}

#endif