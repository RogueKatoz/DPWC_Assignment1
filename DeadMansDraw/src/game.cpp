#include "Game.h"
#include "Card.h"
#include "Player.h"

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

void Game::initialisePlayers()
{

}

void Game::createDeck()
{
}

void Game::shuffleDeck()
{
}

void Game::startGame()
{
}

void Game::playTurn()
{
}

Card* Game::drawCard()
{
	return nullptr;
}

void Game::discardCard(Card&)
{
}

void Game::switchPlayer()
{
}

void Game::endGame()
{
}
