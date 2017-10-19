#include "GameStateTest.h"

namespace engine { namespace state {
	GameStateTest::GameStateTest(Application* applicationPtr, scene::Scene* scenePtr)
	: GameState::GameState(applicationPtr, scenePtr)
	{
		scenePtr->addObject("test_object");
	}

    void GameStateTest::handleInput(sf::Window* window)
    {
        ;
    }

    void GameStateTest::update()
    {
        scenePtr->update();
    }

    void GameStateTest::render(sf::RenderWindow* window)
    {
        scenePtr->render(window);
    }
}}