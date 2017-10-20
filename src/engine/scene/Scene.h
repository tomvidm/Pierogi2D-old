#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SFML/Graphics.hpp"

#include "../Directories.h"

#include "engine/gameobject/Entity.h"
#include "engine/graphics/Sprite.h"
#include "engine/animation/AnimationHandler.h"
#include "engine/graphics/TextureHandler.h"
#include "engine/graphics/Tilemap.h"
#include "engine/lua/LuaHelpers.h"
#include "engine/gui/Window.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"

namespace engine { namespace scene {

    // This class holds all the objects of a scene.

    class Scene 
    {
    public:
        Scene();
        void update();
        void render(sf::RenderWindow* window);

        int addObject(std::string objectName, sf::Window& window);
        void setObjectAnimation(int entity, std::string animation);
        inline graphics::Sprite& getSprite(int index) { return sprites[index]; }
    private:
        std::vector<gameobject::Entity> entities;
        std::vector<graphics::Sprite> sprites;

        graphics::TextureHandler textureHandler;
        animation::AnimationHandler animationHandler;

        sf::RectangleShape measureRect;
        graphics::Tilemap tmap;


    };
}}

#endif