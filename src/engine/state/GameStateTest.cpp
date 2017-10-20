#include <iostream>

#include "GameStateTest.h"

namespace engine { namespace state {
	GameStateTest::GameStateTest(Application* applicationPtr, scene::Scene* scenePtr, sf::RenderWindow* window)
	: GameState::GameState(applicationPtr, scenePtr, window)
	{
        
        
		
        view.setSize(sf::Vector2f(640, 480));
        window->setView(view);
        playerIndex = scenePtr->addObject("test_object", *window);
        scenePtr->getSprite(playerIndex).setAnimation("char2x_standing");
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
                    view.setCenter(engine::input::Mouse::getMouseFloatPos());
                    window->setView(view);
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