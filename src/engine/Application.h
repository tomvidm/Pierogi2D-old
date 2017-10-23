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

#include "Directories.h"

#include "scene/Scene.h"
#include "console/DebugConsole.h"
#include "console/Logger.h"
#include "random/Random.h"
#include "state/GameStateTest.h"
#include "state/GameStateStack.h"
#include "input/Mouse.h"


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

        int screenWidth;
        int screenHeight;

        int maxFramePeriod; 

        bool consoleFocus = false;

        scene::Scene scene;
        state::GameStateStack stateStack;

        sf::Clock mainClock;
        sf::RenderWindow window;

        console::DebugConsole debugConsole;
    };
}

#endif