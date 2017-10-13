#pragma once

#include <queue>
#include <stack>
#include <memory>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "Sprite.h"
#include "graphics/TextureHandler.h"
#include "animation/AnimationHandler.h"
#include "Pool.h"
#include "VectorArray.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"


namespace engine
{
    /*
        Very shitty application class so far.
    */

    class Application
    {
    public:
        void enterLoop();
        void testAnimation();
    private:
        void loop();
        void drawSprites();
        void loadConfiguration();

        sel::State luaState;
        int screenWidth;
        int screenHeight;

        TextureHandler textureHandler;
        AnimationHandler animationHandler;
        Pool<graphics::Sprite, 1024> spritePool;
        graphics::VectorArray varr;
        sf::Clock mainClock;
        sf::RenderWindow window; 
        int maxFramePeriod; 

        graphics::Sprite makeTestSprite();
    };
}