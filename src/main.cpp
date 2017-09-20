#include "engine\GameEngine.h"
#include "engine\states\GameState.h"

int main(int argc, char* argv[])
{
	GameEngine game(1280, 720, "SBS - Sykt Bra Spillmotor V0.000000000000x");
	//TODO: Push the first state (splashscreen/main menu etc) to game
	game.init();
	return 0;
}