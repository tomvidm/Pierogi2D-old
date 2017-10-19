#ifndef GAMESTATETEST_H
#define GAMESTATETEST_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "engine/scene/Scene.h"
#include "engine/input/Mouse.h"

#include "GameState.h"

namespace engine { namespace state { 
	class GameStateTest : public GameState
	{
	public:
		GameStateTest(Application* applicationPtr, scene::Scene* scenePtr);
		virtual void handleInput(sf::Window* window);
        virtual void update();
		virtual void render(sf::RenderWindow* window);		
	};
}}

#endif