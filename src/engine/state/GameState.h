#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "engine/scene/Scene.h"

#include "IGameState.h"

namespace engine { 
	class Application;
namespace state {

	class GameState : public IGameState
	{
	public:
		GameState(Application* applicationPtr, scene::Scene* scenePtr);
	protected:
		Application* applicationPtr;
        scene::Scene* scenePtr;
	};
}}

#endif