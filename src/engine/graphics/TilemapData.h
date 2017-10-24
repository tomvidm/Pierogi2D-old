#ifndef TILEMAPDATA_H
#define TILEMAPDATA_H

#include <map>

#include "SFML/Graphics.hpp"

#include "engine/console/Logger.h"
#include "engine/graphics/TextureManager.h"

namespace engine { namespace graphics {

    // The Tile struct holds information about a Tile.

    struct Tile
    {
        Tile();
        Tile(int u, int v, sf::Vertex* quad, sf::Vector2f texCoords = sf::Vector2f(0, 0));
        int u, v;                   // Coordinates in tilemap
        sf::Vertex* quad = nullptr; // Pointer to first vertex of quad
        sf::Vector2f texCoord;      // Position of upper left texture coordinate
    };

    // The purpose of TilemapData is to encapsulate some of the
    // data for the Tilemap. Tilemap should store data related to world space
    // and graphics, while TilemapData should just store more logic related data.
    // Might be completely unnecessary.

    class TilemapData
    {
    public:
        TilemapData();
        void setSize(int u, int v);

        inline int getSizeU() const { return uSize; }
        inline int getSizeV() const { return vSize; }
        inline void setTile(Tile& tile) { tileVector[coordsToIndex(tile.u, tile.v)] = tile; }

        int coordsToIndex(int u, int v);

        friend class Tilemap;
    protected:
        int uSize;
        int vSize;
        std::vector<Tile> tileVector;
    };

    

}}

#endif