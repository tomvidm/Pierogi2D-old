#ifndef GAMESTATETEST_H
#define GAMESTATETEST_H

#include "SFML/Graphics.hpp"

#include "GameState.h"

namespace engine { namespace state { 
	class GameStateTest : public GameState
	{
	public:
		GameStateTest(Application* applicationPtr);
		virtual void handleInput();
		virtual void render();
		virtual void update();
	};
}}

#endif