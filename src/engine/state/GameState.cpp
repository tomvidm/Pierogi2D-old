#include "GameState.h"

namespace engine { namespace state {
	GameState::GameState(Application* applicationPtr, scene::Scene* scenePtr)
	: applicationPtr(applicationPtr), scenePtr(scenePtr)
	{
		;
	}
}}