#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "engine/IState.h"

namespace engine
{
	class GameState : public IState
	{
	public:
        GameState();
		virtual void handleInput(sf::Window* window);
		virtual void update();
	};
}

#endif