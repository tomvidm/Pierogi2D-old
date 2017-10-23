#include "GameStateStack.h"

namespace engine { namespace state {
	void GameStateStack::pushState(GameState* state)
	{
		_stack.push(state);
		engine::console::Logger::getInstancePtr()->log("Pushed state to stack: " + state->getName() + "\n");
	}

	void GameStateStack::popState()
	{
		_stack.pop();
	}

	GameState* GameStateStack::topState()
	{
		return _stack.top();
	}
}}