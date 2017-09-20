#include "GameState.h"
#include "..\GameEngine.h"

GameState::GameState(GameEngine * game_refference) { game = game_refference; }

GameState::~GameState() {}

void GameState::init()
{

}

void GameState::changeState(GameState * new_state)
{
	game->changeState(new_state);
}

void GameState::pause()
{
	run = false;
}

void GameState::resume()
{
	run = true;
}

void GameState::handleEvents()
{
}

void GameState::update()
{
}

void GameState::draw()
{
}
