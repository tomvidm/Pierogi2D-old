#include "Application.h"

#include "AnimatedSprite.h"
#include "SpriteAnimation.h"

namespace engine {
    void Application::enterLoop() {
        window.create(sf::VideoMode(800, 600), "myproject");
        maxFramePeriod = 16667;
        testAnimation();
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
          for (auto s : spriteVector)
        {
            s.update();
            window.draw(s);
        }
    }

    // Test function. Load texture, assign it to a spriteAnimation.
    // Add frames and hope it works. And of course, push it to the spriteVector.
    void Application::testAnimation()
    {
        texture.loadFromFile("../../resources/images/testsprite.png");
        graphics::AnimatedSprite sprite;
        sprite.setTexture(texture);
        graphics::SpriteAnimation anim;
        graphics::Frame frame;
        frame.duration = 10*16667;
        frame.texRect = sf::Rect<int>(sf::Vector2i(0, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*2, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*3, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*4, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*5, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*6, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*7, 0), sf::Vector2i(184, 375));
        anim.addFrame(frame);

        sprite.setAnimation(anim);
        // Define animation here!!!
        spriteVector.push_back(sprite);
    }
}