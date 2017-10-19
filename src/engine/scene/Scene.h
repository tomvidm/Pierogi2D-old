#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SFML/Graphics.hpp"

#include "../Directories.h"

#include "engine/gameobject/Entity.h"
#include "engine/graphics/Sprite.h"
#include "engine/animation/AnimationHandler.h"
#include "engine/graphics/TextureHandler.h"
#include "engine/lua/LuaHelpers.h"

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
        void update();
        void render(sf::RenderWindow* window);

        void addObject(std::string objectName);
    private:
        std::vector<gameobject::Entity> entities;
        std::vector<graphics::Sprite> sprites;

        graphics::TextureHandler textureHandler;
        animation::AnimationHandler animationHandler;

    };
}}

#endif