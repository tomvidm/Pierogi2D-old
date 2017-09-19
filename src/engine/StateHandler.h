/*
	The StateHandler handles states, taking care of pushing
	and popping states as needed. It holds a stack of shared pointers
	to base states to enable polymorphic behaviour.

	The interface should be common enough so that the state handler can be a
	general purpose handler for both the main game loops and a
	handler for individual objects and Ai's.

	TODO: 	* How should knowledge about other parts of the system be passed to the state handler
		  	and states?
		  	* How to effectively implement polymorphism? HODEPINE JAAA
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