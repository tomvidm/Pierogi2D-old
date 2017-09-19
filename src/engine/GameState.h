#include "BaseState.h"

namespace engine
{
	class GameState : public BaseState
	{
	public:
		virtual void execute() = 0;
		virtual void handleInput() = 0;
		virtual void handleResources() = 0;
	};
}