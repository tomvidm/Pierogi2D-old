#include "Application.h"



namespace engine {
    void Application::start() {
        loadConfiguration();
        window.create(sf::VideoMode(screenWidth, screenHeight), "myproject");
        stateStack.pushState(GameState());
        debugConsole.initDefaultConsoleFont();
        debugConsole.addLine("Hello World!");

        while (window.isOpen())
        {
            loop();
        }
    }

    void Application::loop() {
        stateStack.topState()->handleInput(&window);
        stateStack.topState()->update();
        debugConsole.update();
        handleRendering();
    }

    void Application::handleRendering()
    {
        if (mainClock.getElapsedTime().asMicroseconds() > maxFramePeriod)
        {
            mainClock.restart();
            window.clear();

            // DRAW THINGS
            //drawSprites();
            window.draw(debugConsole);

            window.display();
        }
    }

    void Application::drawSprites()
    {
        for (uint i = 0; i < spritePool.getFirstFreeIndex(); i++)
        {
            if ((spritePool.getState(i) & ACTIVE) == ACTIVE)
            {
                spritePool.get(i).update();
                window.draw(spritePool.get(i));
            }
        }
    }

    void Application::loadConfiguration()
    {
        sel::State luaState;
        luaState.Load("../../src/engine/conf.lua");
        screenWidth = static_cast<int>(luaState["configuration"]["screenWidth"]);
        screenHeight = static_cast<int>(luaState["configuration"]["screenHeight"]);
        maxFramePeriod = static_cast<int>(luaState["configuration"]["maxFramePeriod"]);
        return; // Use Lua to load basic configuration such as window size etc
    }

    graphics::Sprite Application::makeTestSprite()
    {
        //animationHandler.loadTestData();
        animationHandler.loadFromLuaTable("../../resources/images/spritesheet_testsprite.lua", "spritesheet_testsprite");
        textureHandler.loadFromFile("../../resources/images/testsprite.png", "testsprite");

        graphics::Sprite sprite;
        sprite.setTexture(textureHandler.get("testsprite"));
        
        sprite.setAnimation(animationHandler.get("testsprite_walk_right_wild"));
        return sprite;
    }
}


    