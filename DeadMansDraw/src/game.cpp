#include "Game.h"
#include "Card.h"
#include "Player.h"

#include <bits/stdc++.h>
#include <iostream>

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
	_otherPlayer = 1;

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
	while (endGame() == 0)
	{
		playTurn();
		switchPlayer();
	}
}

bool Game::endGame() const
// End game if max turns are reached or deck is empty.
{
	if (_currentTurn > MAX_TURNS || _deck.empty())
	{
		return true;
	}
	else return false;
}

void Game::playTurn()
// Go through single turn for current player.
{
	while (1)
	{
		// Draw and play card if deck is not empty.
		Card* cardToPlay = drawCard();
		if (cardToPlay == NULL) break;
		_players[_currentPlayer]->playCard(cardToPlay, this);

		// Check if player is bust and break, or ask for another card.
		if (_players[_currentPlayer]->isBust() == 1) break;
		if (promptDrawCard() == 0)
		{
			_players[_currentPlayer]->bankPlayedCards();
			break;
		}
	}
}

bool Game::promptDrawCard()
// It will be assumed that if any character other than 'y' is entered, turn ends.
{
	char input;
	std::cout << "Draw again? (y/n): ");
	std::cin.get(input);
	std::endl;
	if (input == 'y')
	{
		return 1;
	}
	else return 0;
}

Card* Game::drawCard()
{
	return _deck.pop();
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