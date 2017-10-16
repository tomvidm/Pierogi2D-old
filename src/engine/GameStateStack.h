#pragma once

#include <stack>

#include "GameState.h"

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