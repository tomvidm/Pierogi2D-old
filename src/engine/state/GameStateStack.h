#ifndef GAMESTATESTACK_H
#define GAMESTATESTACK_H

#include <stack>

#include "GameState.h"
#include "engine/console/Logger.h"

namespace engine { namespace state {
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
}}

#endif