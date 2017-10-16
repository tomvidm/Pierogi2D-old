#include "GameState.h"

namespace engine
{
    GameState::GameState()
    {
        ;
    }

    void GameState::update()
    {
        ;
    }

    void GameState::handleInput(sf::Window* window)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
    }
}