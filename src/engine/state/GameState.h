#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "IGameState.h"

namespace engine { 
	class Application;
    class Scene;
namespace state {

	class GameState : public IGameState
	{
	public:
		GameState(Application* applicationPtr, Scene* scenePtr);
	protected:
		Application* applicationPtr;
        Scene* scenePtr;
	};
}}

#endif