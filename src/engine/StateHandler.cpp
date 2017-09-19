#include "StateHandler.h"

namespace engine
{
	void StateHandler::pop()
	{
		stateStack_.pop();
	}

	BaseStatePtr peek() const
	{
		return stateStack_.top();
	}
}