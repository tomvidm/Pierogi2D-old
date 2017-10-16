#include "GameStateStack.h"

namespace engine
{
	void GameStateStack::pushState(GameState* state)
	{
		_ptrStack.push(state);
	}

	void GameStateStack::popState()
	{
		_ptrStack.pop();
	}

	GameState* GameStateStack::topState()
	{
		return _ptrStack.top();
	}
}