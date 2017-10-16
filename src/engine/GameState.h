#pragma once

#include "IState.h"

namespace engine
{
	class GameState : public IState
	{
	public:
		virtual void handleInput();
		virtual void update();
	};
}