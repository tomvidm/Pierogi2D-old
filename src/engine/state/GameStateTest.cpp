#include <iostream>

#include "GameStateTest.h"

namespace engine { namespace state {
	GameStateTest::GameStateTest(Application* applicationPtr, scene::Scene* scenePtr)
	: GameState::GameState(applicationPtr, scenePtr)
	{
		scenePtr->addObject("test_object");
	}

    void GameStateTest::handleInput(sf::Window* window)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed ||
                event.type == sf::Event::MouseButtonReleased)
            {
                input::MouseEvent mouseEvent = input::Mouse::getMouseEvent(event);
                switch (mouseEvent)
                {
                    case input::MouseEvent::LEFT_CLICKED:
                        std::cout << "LEFT CLICK" << std::endl;
                        break;
                    case input::MouseEvent::LEFT_RELEASED:
                        std::cout << "LEFT HOLD RELEASED" << std::endl;
                        break;
                    default:
                        break;
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