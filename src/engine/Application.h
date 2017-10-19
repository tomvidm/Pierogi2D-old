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

#include "Scene.h"
#include "Directories.h"
#include "Pool.h"


#include "console/DebugConsole.h"
#include "random/Random.h"
#include "state/GameStateTest.h"
#include "state/GameStateStack.h"


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

        Scene scene;
        state::GameStateStack stateStack;

        sf::Clock mainClock;
        sf::RenderWindow window;

        console::DebugConsole debugConsole;
    };
}

#endif