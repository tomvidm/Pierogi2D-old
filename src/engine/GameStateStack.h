#include <stack>

namespace engine
{
	class GameState;

	typedef std::stack<GameState> StateStack;

	class GameStateStack
	{
	public:
		void push(GameState& state);
		void pop();
		GameState* top();
	private:
		StateStack _stack;
	};
}