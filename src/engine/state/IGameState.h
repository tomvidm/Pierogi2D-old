#ifndef IGAMESTATE_H
#define IGAMESTATE_H

namespace sf {
        class Window;
        class RenderWindow;
}

namespace engine { namespace state {

	class IGameState 
	{
	public:
		virtual void update(float dt) = 0;
		virtual void handleInput(sf::RenderWindow* window) = 0;
		virtual void render(sf::RenderWindow* window) = 0;
	};
}}

#endif