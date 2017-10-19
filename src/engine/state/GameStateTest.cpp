#include <iostream>

#include "GameStateTest.h"

namespace engine { namespace state {
	GameStateTest::GameStateTest(Application* applicationPtr, scene::Scene* scenePtr)
	: GameState::GameState(applicationPtr, scenePtr)
	{
		;
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
                    std::cout << "LEFT CLIK!!!" << std::endl;
                    sf::Vector2i mpos = input::Mouse::getMousePos(*window);
                    std::cout << mpos.x << ", " << mpos.y << std::endl;
                    scenePtr->addObject("test_object", *window);
                }
                else if (input::Mouse::isRightClick(event))
                {
                    std::cout << "RIGHT CLICK!!!" << std::endl;
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