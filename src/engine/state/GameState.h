#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "IGameState.h"

namespace engine { 
	class Application;
namespace state {

	class GameState : public IGameState
	{
	public:
		GameState(Application* applicationPtr);
	protected:
		Application* applicationPtr_;
	};
}}

#endif