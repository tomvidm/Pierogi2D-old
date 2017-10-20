#include "GameState.h"

namespace engine { namespace state {
	GameState::GameState(Application* applicationPtr, scene::Scene* scenePtr, sf::Window* window)
	: applicationPtr(applicationPtr), scenePtr(scenePtr), windowPtr(window)
	{
		;
	}
}}