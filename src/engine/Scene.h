#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SFML/Graphics.hpp"

#include "Directories.h"

#include "Entity.h"
#include "graphics/Sprite.h"
#include "animation/AnimationHandler.h"
#include "graphics/TextureHandler.h"
#include "lua/LuaHelpers.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"

namespace engine { 

    // This class holds all the objects of a scene.

    class Scene 
    {
    public:
        void update();
        void render(sf::RenderWindow* window);

        void addObject(std::string objectName);
    private:
        std::vector<Entity> entities;
        std::vector<graphics::Sprite> sprites;

        graphics::TextureHandler textureHandler;
        animation::AnimationHandler animationHandler;

    };
}

#endif