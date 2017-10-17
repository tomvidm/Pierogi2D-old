#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <queue>
#include <stack>
#include <memory>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "animation/AnimationHandler.h"
#include "graphics/Sprite.h"
#include "graphics/TextureHandler.h"
#include "console/DebugConsole.h"

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
        void collectEvents();
        void handleRendering();
        void drawSprites();
        void loadConfiguration();

        int screenWidth;
        int screenHeight;
        int maxFramePeriod; 

        TextureHandler textureHandler;
        AnimationHandler animationHandler;

        GameStateStack stateStack;

        sf::Clock mainClock;
        sf::RenderWindow window;

        Pool<graphics::Sprite, 1024> spritePool;

        console::DebugConsole debugConsole;
        std::vector<sf::Event> eventVector;

        graphics::Sprite makeTestSprite();
    };
}

#endif