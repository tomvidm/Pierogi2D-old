#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "engine/IState.h"

namespace engine
{
	class Application;
	class sf::RenderWindow;

	class GameState : public IState
	{
	public:
		GameState(Application* applicationPtr);
		virtual void handleInput(sf::RenderWindow* window) = 0;
		virtual void render() = 0;
		virtual void update() = 0;
	protected:
		Application* applicationPtr_;
	};
}

#endif