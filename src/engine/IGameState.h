#ifndef IGAMESTATE_H
#define IGAMESTATE_H

namespace engine {
	class IGameState
	{
	public:
		virtual void update() = 0;
		virtual void handleInput() = 0;
		virtual void render() = 0;
	};
}

#endif