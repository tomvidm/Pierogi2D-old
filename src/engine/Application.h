#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <queue>
#include <stack>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "animation/AnimationHandler.h"
#include "graphics/Sprite.h"
#include "graphics/TextureHandler.h"
#include "console/DebugConsole.h"
#include "random/Random.h"
#include "Directories.h"

#include "GameState.h"
#include "GameStateStack.h"
#include "Pool.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"


namespace engine
{
    // This is the top level class holding all of the information
    // of the running engine. Look in the cpp file for details.

    class Application
    {
    public:
        void start();
    private:
        void loop();
        
        void loadConfiguration();

        void collectEvents();

        void handleRendering();
        void drawSprites();

        int screenWidth;
        int screenHeight;
        int maxFramePeriod; 

        bool consoleFocus = false;

        TextureHandler textureHandler;
        AnimationHandler animationHandler;

        GameStateStack stateStack;

        sf::Clock mainClock;
        sf::RenderWindow window;

        Pool<graphics::Sprite, 512> spritePool;
        std::vector<graphics::Sprite> spriteVector;

        console::DebugConsole debugConsole;

        std::vector<sf::Event> eventVector;

        graphics::Sprite loadSprite(std::string spritename, std::string animation);
        void setSprite(graphics::Sprite& sprite, std::string spritename, std::string animation);
    };
}

#endif