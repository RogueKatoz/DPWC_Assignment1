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
// Call initialisation stuff.
{
	_currentRound = 0;
	_currentTurn = 0;

	initialisePlayers();
	createDeck();
	shuffleDeck();
}
