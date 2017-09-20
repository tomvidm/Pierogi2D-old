#ifndef GAMEENGINE_H
#define GAMEENGINE_H 
#include "..\..\..\Include\SFML\Graphics.hpp"
#include <vector>
#include "states\GameState.h"

class GameEngine
{
public:

	void init();
	void quit();
	//TODO: Cleanup-function

	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();

	void handleEvents();
	void update();
	void draw();

	sf::RenderWindow& getWindow();

	GameEngine(int width, int height, std::string title);
	~GameEngine();

private:
	std::vector <GameState*> states;
	sf::Clock timer;
	sf::RenderWindow g_window;
	bool run = true;
	bool window_focus = true;
	bool run_minimized = true;
};

#endif