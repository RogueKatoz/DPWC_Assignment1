#include "Game.h"

Game::Game()
// Create inital states for the game.
{
	_players = nullptr;
	_deck = nullptr;
	_discardPile = nullptr;
	_currentRound = 0;
	_currentTurn = 0;
}

Game::~Game()
// Cleanup.
{

}

void Game::initialiseGame()
// Create deck & initialise players
{

}
