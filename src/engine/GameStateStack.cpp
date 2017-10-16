#include "GameStateStack.h"

namespace engine
{
	void GameStateStack::pushState(GameState state)
	{
		_stack.push(state);
	}

	void GameStateStack::popState()
	{
		_stack.pop();
	}

	GameState* GameStateStack::topState()
	{
		return &_stack.top();
	}
}