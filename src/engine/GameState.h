#pragma once

#include "IState.h"
#include "SFML/Graphics.hpp"

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