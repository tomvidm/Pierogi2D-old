#pragma once

#include <cmath>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../Utility.h"
#include "engine/input/Mouse.h"
#include "engine/graphics/TextureManager.h"
#include "engine/graphics/TilemapData.h"

namespace engine {
namespace graphics {

    class Tilemap : public sf::Drawable, public sf::Transformable
    {
    public:
        Tilemap();
        void setSize(int u, int v);

        void allocateVertices();
        void allocateVerticesOrdered();

        void setTilePlacement(int u, int v);

        void setTexture(std::string texture);
        void setTextureToTile(int u, int v, sf::Vector2f position, sf::Vector2f size);
        void update();
        //void setTexture(sf::Texture& tex);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        inline void setGridVisibility(const bool& showOrNot) { showGrid = showOrNot; }
        inline bool gridIsVisible() const { return showGrid; }

        inline int getSizeU() const { return tilemapData.getSizeU(); }
        inline int getSizeV() const { return tilemapData.getSizeV(); }

        sf::Vector2i getMouseOverVector() const;
    private:
        bool showGrid;
        float uScale = 32.f;
        float vScale = 32.f;
        sf::Vector2f uVector = uScale*sf::Vector2f(1.f, 0.5f);
        sf::Vector2f vVector = vScale*sf::Vector2f(-1.f, 0.5f);
        sf::Vertex* getQuad(int u, int v);
        sf::Texture* texturePtr = nullptr;

        TilemapData tilemapData;

        sf::VertexArray varr;
        sf::VertexArray grid;
    };

}
}