#include "GameState.h"

namespace engine { namespace state {
	GameState::GameState(Application* applicationPtr, Scene* scenePtr)
	: applicationPtr(applicationPtr), scenePtr(scenePtr)
	{
		;
	}
}}