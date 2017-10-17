#ifndef GAMESTATESTACK_H
#define GAMESTATESTACK_H

#include <stack>

#include "engine/GameState.h"

namespace engine
{
	typedef std::stack<GameState> StateStack;

	class GameStateStack
	{
	public:
		void pushState(GameState state);
		void popState();
		
		GameState* topState();
	private:
		StateStack _stack;
	};
}

#endif