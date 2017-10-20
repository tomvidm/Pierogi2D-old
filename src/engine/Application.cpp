#include "Application.h"

#include <iostream>

namespace engine {
    // This function is meant to initialize all the necessary parts
    // of the "game". Until this engine become fully capable of giving
    // Lua scripts the ability to call functions like "CREATE A FRIGGIN OBJECT",
    // this will be the playground.
    void Application::start() {
        loadConfiguration();
        window.create(sf::VideoMode(screenWidth, screenHeight), "myproject");
        srand(static_cast<unsigned int>(time(NULL)));
        stateStack.pushState(new state::GameStateTest(this, &scene, &window));
        
        while (window.isOpen())
        {
            loop();
        }
    }

    void Application::loop() {
        stateStack.topState()->handleInput(&window);
        stateStack.topState()->update();
        stateStack.topState()->render(&window);
    }

/*    // This is self explanatory and this method will change a lot.
    void Application::handleRendering()
    {
        // Using the mainClock, the framerate is kept near constant.
        // (Should probably be minFramePeriod???)
        if (mainClock.getElapsedTime().asMicroseconds() > maxFramePeriod)
        {
            mainClock.restart();
            window.clear(sf::Color::White);

            // DRAW THINGS
            drawSprites();
            window.draw(debugConsole);

            window.display();
        }
    }
*/
    // Basic configurations like resolution and frame rate is
    // currently stored in a lua file and loaded here using
    // the Selene Lua wrapper for c++.
    void Application::loadConfiguration()
    {
        sel::State luaState;
        luaState.Load("../../src/engine/conf.lua");
        screenWidth = static_cast<int>(luaState["configuration"]["screenWidth"]);
        screenHeight = static_cast<int>(luaState["configuration"]["screenHeight"]);
        maxFramePeriod = static_cast<int>(luaState["configuration"]["maxFramePeriod"]);
        return; // Use Lua to load basic configuration such as window size etc
    }
}


    