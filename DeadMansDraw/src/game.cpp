#include "Game.h"
#include "Card.h"
#include "Player.h"

Game::Game()
// Create inital states for the game.
{
	_players = { nullptr, nullptr };
	_deck = nullptr;
	_discardPile = nullptr;
	_currentRound = 0;
	_currentTurn = 0;
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
// Create player objects
{
	_players[0] = new Player();
	_players[1] = new Player();
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

Game::~Game()
// Cleanup.
{
	delete _players[0];
	delete _players[1];
}