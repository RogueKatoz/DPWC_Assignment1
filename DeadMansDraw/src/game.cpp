#include "Game.h"
#include "Card.h"
#include "Player.h"

#include <bits/stdc++.h>

#define MAX_TURNS 20

Game::Game()
// Create inital states for the game.
{
	_players = { nullptr, nullptr };
	_deck = new CardCollection;
	_discardPile = new CardCollection;
	_currentRound = 0;
	_currentTurn = 0;
}

void Game::initialiseGame()
// Call initialisation stuff.
{
	_currentRound = 0;
	_currentTurn = 0;
	_currentPlayer = 0;

	initialisePlayers();
	createDeck();
	shuffleDeck();
}

void Game::initialisePlayers()
// Create both players.
{
	_players[0] = new Player();
	_players[1] = new Player();
}

void Game::createDeck()
// Add 6 cards of each suit to the deck collection.
{
	CardType typeList[] = { Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken };

	for (CardType type : typeList)
	{
		if (type == Mermaid)
		{
			for (int val = 4; val <= 9; val++)
			{
				_deck.push_back(new Card(type, val))
			}
		}
		else
		{
			for (int val = 2; val <= 7; val++)
			{
				_deck.push_back(new Card(type, val))
			}
		}
	}
}

void Game::shuffleDeck() const
{
	random_shuffle(_deck.begin(), _deck.end());
}

void Game::startGame()
// Initialise and then play through turns, ending if condition is met.
{
	initialiseGame();
	while (gameEnd == 0)
	{
		playTurn();
		switchPlayer();
	}
}

bool Game::gameEnd() const
{
	if (_currentTurn > MAX_TURNS || _deck.empty())
	{
		return true;
	}
	else return false;
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