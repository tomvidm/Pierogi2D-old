#pragma once

namespace engine {
	class IState
	{
	public:
		virtual void update() = 0;
	};
}