#ifndef ISTATE_H
#define ISTATE_H

namespace engine {
	class IState
	{
	public:
		virtual void update() = 0;
	};
}

#endif