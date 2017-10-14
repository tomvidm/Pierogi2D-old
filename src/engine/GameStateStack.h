#include <stack>

namespace engine
{
	class GameState;

	typedef std::stack<GameState> StateStack;

	class GameStateStack
	{
	public:
		void pushState(GameState& state);
		void popState();
		GameState* topState();
	private:
		StateStack _stack;
	};
}