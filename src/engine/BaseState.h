/*
	Abstract class for game states.
	The execute method should be common for all derived classes.
	When called through polymorphism, execute should
	be the common interface, and more specialized methods
	should be added to derived classes.
*/

namespace engine
{
	class BaseState
	{
	public:
		virtual void execute() = 0;
	};
}