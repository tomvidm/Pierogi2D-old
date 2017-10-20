#ifndef GAMESTATETEST_H
#define GAMESTATETEST_H

#include "GameState.h"

namespace engine {
	class GameStateTest : public GameState
	{
	public:
		GameStateTest(Application* applicationPtr);
		virtual void handleInput(sf::Window* window);
		virtual void render();
		virtual void update();
	private:
		sf::View view(sf::FloatRect(0, 0, 640, 480));
	}
}

#endif