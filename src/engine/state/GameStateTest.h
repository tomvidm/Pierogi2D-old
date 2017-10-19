#ifndef GAMESTATETEST_H
#define GAMESTATETEST_H

#include "SFML/Graphics.hpp"

#include "GameState.h"

namespace engine { namespace state { 
	class GameStateTest : public GameState
	{
	public:
		GameStateTest(Application* applicationPtr);
		virtual void handleInput(sf::Window* window);
		virtual void render(sf::RenderWindow* window);
		virtual void update();
	};
}}

#endif