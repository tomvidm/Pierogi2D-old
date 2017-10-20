#include <iostream>

#include "GameStateTest.h"

namespace engine { namespace state {
	GameStateTest::GameStateTest(Application* applicationPtr, scene::Scene* scenePtr, sf::Window* windowPtr)
	: GameState::GameState(applicationPtr, scenePtr, windowPtr)
	{
		playerIndex = scenePtr->addObject("test_object", *windowPtr);
        scenePtr->getSprite(playerIndex).setAnimation("char2x_standing");
	}

    void GameStateTest::handleInput(sf::Window* window)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                input::Mouse::registerButtonPressEvent(event);
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (input::Mouse::isLeftClick(event))
                {
                    std::cout << "Left click." << std::endl;
                    scenePtr->getSprite(playerIndex).setAnimation("char2x_running");
                }
                else if (input::Mouse::isRightClick(event))
                {
                    std::cout << "Right click." << std::endl;
                    scenePtr->getSprite(playerIndex).setAnimation("char2x_standing");
                }
            }
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