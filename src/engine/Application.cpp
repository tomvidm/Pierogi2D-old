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
        srand(time(NULL));
        stateStack.pushState(new state::GameStateTest(this));
        
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

    // This method pushes all the events to the 
    // private variable eventVector.
    // The solution is temporary, but the motivation is this:
    // When calling pollEvent on a window, events are popped from a stack.
    // When more than one object needs to respond to some event,
    // it is better to store the events and pass a reference to this vector
    // than to have a monolithic function send every imaginable input to 
    // the relevant objects.
    void Application::collectEvents()
    {
        //eventVector.clear();
        
        /*sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    spriteVector.push_back(loadSprite("testsprite2", "running"));
                }
            }

            if (event.type == sf::Event::TextEntered)
            {
                debugConsole.update();
                if (static_cast<int>(event.text.unicode) == 3) // CTRL + C
                {
                    std::cout << "Toggle console " << std::endl;
                    consoleFocus = !consoleFocus;
                    return;
                }
                else if (consoleFocus)
                {
                    debugConsole.handleEvent(event);
                    return;
                }
            }

            eventVector.push_back(event);
        }*/
    }

    // This is self explanatory and this method will change a lot.
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

    // This runs through the sprites in the spritePool and draws them.
    // One problem will be to handle differing "depth" with different kinds
    // of drawables. VertexArrays, Sprites and so on will need to be handled
    // separately which will create headaches.
    // NEEDS SOME EXTRA R&D TO FIND SOME NEAT WAY TO DO THIS
    void Application::drawSprites()
    {
        for (auto s = spriteVector.begin(); s != spriteVector.end(); s++)
        {
            s->update();
            window.draw(*s);
        }
       
/*        for (uint i = 0; i < spritePool.getFirstFreeIndex(); i++)
        {
            if ((spritePool.getState(i) & ACTIVE) == ACTIVE)
            {
                spritePool.get(i).update();
                window.draw(spritePool.get(i));
            }
        }*/
    }

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

    graphics::Sprite Application::loadSprite(std::string spritename, std::string animation)
    {
        animationHandler.loadFromFile(spritename);
        textureHandler.loadFromFile(spritename);
        graphics::Sprite sprite;
        sprite.setTexture(textureHandler.get(spritename));
        sprite.setAnimation(animationHandler.get(spritename + "_" + animation));
        sprite.updateRect();
        sprite.setScale(sf::Vector2f(3.f, 3.f));
        return sprite;
    }

    void Application::setSprite(graphics::Sprite& sprite, std::string spritename, std::string animation)
    {
        animationHandler.loadFromFile(spritename);
        textureHandler.loadFromFile(spritename);
        
        sprite.setTexture(textureHandler.get(spritename));
        sprite.setAnimation(animationHandler.get(spritename + "_" + animation));
        sprite.updateRect();
    }
}


    