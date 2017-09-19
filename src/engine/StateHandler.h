/*
	The StateHandler handles states, taking care of pushing
	and popping states as needed. It holds a stack of shared pointers
	to base states to enable polymorphic behaviour.
*/

#include <memory>
#include <stack>

#include "BaseState.h"

namespace engine
{
	typedef std::shared_ptr<BaseState> BaseStatePtr;
	typedef std::stack<BaseStatePtr> StatePtrStack;

	class StateHandler
	{
	public:
		virtual void handleNextState();
	private:
		StatePtrStack stateStack_;

		void pop();
		BaseStatePtr peek() const;
	};
}