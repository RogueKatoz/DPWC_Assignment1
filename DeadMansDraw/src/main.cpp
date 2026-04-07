#include <iostream>
#include "Game.h"

int main()
{
	Game game;
	game.startGame();

	delete game;
	return 0;
}