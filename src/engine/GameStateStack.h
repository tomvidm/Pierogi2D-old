#ifndef GAMESTATESTACK_H
#define GAMESTATESTACK_H

#include <stack>

#include "engine/GameState.h"

namespace engine
{
	typedef std::stack<GameState*> StatePtrStack;

	class GameStateStack
	{
	public:
		void pushState(GameState* state);
		void popState();
		
		GameState* topState();
	private:
		StatePtrStack _stack;
	};
}

#endif