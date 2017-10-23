#ifndef TILEMAPDATA_H
#define TILEMAPDATA_H

#include <map>

#include "SFML/Graphics.hpp"

#include "engine/console/Logger.h"
#include "engine/graphics/TextureHandler.h"

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

        inline int getSizeU() const { return uSize; }
        inline int getSizeV() const { return vSize; }

        friend class Tilemap;
    protected:
        int uSize;
        int vSize;
        std::vector<Tile> tileVector;

        sf::Texture* texturePtr = nullptr;
        TextureHandler* textureHandlerPtr = nullptr;
    };

    int coordsToIndex(int u, int v);

}}

#endif