#include "GameEngine.h"
#include <iostream>

void GameEngine::init() {

	unsigned TPS = 30;

	g_window.setFramerateLimit(TPS);

	while (g_window.isOpen())
	{

		sf::Time elapsed = timer.getElapsedTime();

		sf::Event e;

		while (g_window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) {
				g_window.close();
			}

			else if (e.type == sf::Event::GainedFocus) {
				window_focus = true;
			}

			else if (e.type == sf::Event::LostFocus) {
				window_focus = false;
			}
		}


		if (run && elapsed.asMilliseconds() > 1000.f / float(TPS)) {
			timer.restart();
			if (window_focus) {
				handleEvents();
			}

			if (!run_minimized && !window_focus) {
				continue;
			}

			update();
			draw();
		}
	}
}

void GameEngine::quit()
{
	run = false;
	//TODO: Call cleanup
}

void GameEngine::changeState(GameState* state)
{
	//TODO: Clean up all states
	states.clear();
	//TODO: Init state by pushing

}

void GameEngine::pushState(GameState* state)
{
	states.push_back(state);
}

void GameEngine::popState()
{
	states.pop_back();
}

void GameEngine::handleEvents()
{
	for (int i = 0; i < states.size(); i++)
		states.at(i)->handleEvents();
}

void GameEngine::update()
{
	for (int i = 0; i < states.size(); i++)
		states.at(i)->update();
}

void GameEngine::draw()
{
	for (int i = 0; i < states.size(); i++)
		states.at(i)->draw();

	//g_window.display();
}

GameEngine::GameEngine(int width, int height, std::string title) : g_window(sf::VideoMode(width, height), title) {}

sf::RenderWindow& GameEngine::getWindow()
{
	return g_window;
}


GameEngine::~GameEngine() {
}
