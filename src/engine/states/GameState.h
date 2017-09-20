#ifndef GAMESTATE_H
#define GAMESTATE_H 

class GameEngine;

class GameState
{
public:

	virtual void init();
	virtual void changeState(GameState* new_state);
	//TODO: Cleanup

	virtual void pause();
	virtual void resume();

	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	GameState(GameEngine * game_refference);
	~GameState();

protected:
	GameEngine* game;
	bool run = true;
};
#endif