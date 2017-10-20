#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "engine/scene/Scene.h"

#include "IGameState.h"

namespace engine { 
	class Application;
namespace state {

	class GameState : public IGameState
	{
	public:
		GameState(Application* applicationPtr, scene::Scene* scenePtr, sf::Window* window);
	protected:
		Application* applicationPtr;
        scene::Scene* scenePtr;
        sf::Window* windowPtr;
	};
}}

#endif