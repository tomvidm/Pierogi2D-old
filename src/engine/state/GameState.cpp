#include "GameState.h"

namespace engine { namespace state {
	GameState::GameState(Application* applicationPtr, scene::Scene* scenePtr, sf::RenderWindow* window)
	: applicationPtr(applicationPtr), scenePtr(scenePtr), windowPtr(window)
	{
		;
	}
}}