#include "Application.h"

namespace engine {
    void Application::enterLoop() {
        loadConfiguration();
        window.create(sf::VideoMode(screenWidth, screenHeight), "myproject");
        maxFramePeriod = 16667;
        graphics::Sprite s = makeTestSprite();
        spritePool.pushObject(s);
        while (window.isOpen())
        {
            loop();
        }
    }

    void Application::loop() {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }

        if (mainClock.getElapsedTime().asMicroseconds() > maxFramePeriod)
        {
            mainClock.restart();
            window.clear();
            drawSprites();
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
        window.draw(varr);
    }

    void Application::loadConfiguration()
    {
        luaState.Load("../../src/engine/conf.lua");
        screenWidth = static_cast<int>(luaState["configuration"]["screenWidth"]);
        screenHeight = static_cast<int>(luaState["configuration"]["screenHeight"]);
        return; // Use Lua to load basic configuration such as window size etc
    }

    // Test function. Load texture, assign it to a spriteAnimation.
    // Add frames and hope it works. And of course, push it to the spriteVector.
    void Application::testAnimation()
    {
        //graphics::AnimatedSprite sprite = makeTestSprite();
        spritePool.pushObject(makeTestSprite());
        
    }

    graphics::Sprite Application::makeTestSprite()
    {
        animationHandler.loadFromLuaTable("../../resources/images/spritesheet_testsprite.lua", "spritesheet_testsprite");
        textureHandler.loadFromFile("../../resources/images/testsprite.png", "testsprite");

        graphics::Sprite sprite;
        sprite.setTexture(textureHandler.get("spritesheet_testsprite"));
        
        sprite.setAnimation(animationHandler.get("spritesheet_testsprite"));
        return sprite;
    }
}


    