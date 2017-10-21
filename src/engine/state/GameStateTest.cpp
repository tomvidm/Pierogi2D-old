#include <iostream>

#include "GameStateTest.h"

namespace engine { namespace state {
	GameStateTest::GameStateTest(Application* applicationPtr, scene::Scene* scenePtr, sf::RenderWindow* window)
	: GameState::GameState(applicationPtr, scenePtr, window)
	{
        
        
		
        view.setSize(sf::Vector2f(640, 480));
        window->setView(view);
        playerIndex = scenePtr->addObject("test_object", *window);
        scenePtr->getSprite(playerIndex).setAnimation("testsprite2_standing");
	}

    void GameStateTest::handleInput(sf::RenderWindow* window)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                windowPtr->close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                input::Mouse::registerButtonPressEvent(event);
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (input::Mouse::isLeftClick(event))
                {
                    
                    std::cout << "Left click." << std::endl;
                    scenePtr->getSprite(playerIndex).setAnimation("testsprite2_running");
                }
                else if (input::Mouse::isRightClick(event))
                {
                    std::cout << "Right click." << std::endl;
                    scenePtr->getSprite(playerIndex).setAnimation("testsprite2_standing");
                }
            }
        }

        if (engine::input::Mouse::isLeftHold())
        {
            view.move(-engine::input::Mouse::getMouseFloatPos()
                                + engine::input::Mouse::getPositionOnLeftPress());
            window->setView(view);
        }
    }

    void GameStateTest::update()
    {
        scenePtr->update();
    }

    void GameStateTest::render(sf::RenderWindow* window)
    {
        scenePtr->render(window);
    }
}}