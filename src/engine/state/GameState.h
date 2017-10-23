#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

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
		GameState(Application* applicationPtr, scene::Scene* scenePtr, sf::RenderWindow* window);

		inline std::string getName() const { return stateName; }
	protected:
		std::string stateName;
		Application* applicationPtr;
        scene::Scene* scenePtr;
        sf::RenderWindow* windowPtr;
	};
}}

#endif