#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "game_title.h"

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define MAX_TURNS 20

Game::Game()
// Create inital states for the game.
{
	_players[0] = nullptr;
	_players[1] = nullptr;
	_deck = new CardCollection;
	_discardPile = new CardCollection;
	_currentRound = 1;
	_currentTurn = 1;
	_currentPlayer = 0;
}

void Game::initialiseGame()
// Call initialisation stuff.
{
	initialisePlayers();
	createDeck();
	shuffleDeck();

std::cout << GAME_TITLE_H << std::endl;
std::cout << "Starting Dead Man's Draw++!" << std::endl;
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
	for (CardType type : CARD_TYPES)
	{
		if (type == Mermaid)
		{
			for (int val = 4; val <= 9; val++)
			{
				_deck->push_back(new Card(type, val));
			}
		}
		else
		{
			for (int val = 2; val <= 7; val++)
			{
				_deck->push_back(new Card(type, val));
			}
		}
	}
}

void Game::shuffleDeck() const
{
	srand(unsigned(time(NULL)));
	std::random_shuffle(_deck->begin(), _deck->end());
}

void Game::startGame()
// Initialise and then play through turns, ending if condition is met.
{
	initialiseGame();
	while (endGame() == 0)
	{
		std::cout << "--- Round " << _currentRound << ", Turn " << _currentTurn << " ---" << std::endl;

		playTurn();
		switchPlayer();
	}
}

bool Game::endGame() const
// End game if max turns are reached or deck is empty.
{
	if (_currentTurn > MAX_TURNS || _deck->empty())
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
	std::cout << "Draw again? (y/n): ";
	std::cin.get(input);
	if (input == 'y')
	{
		return 1;
	}
	else return 0;
}

Card* Game::drawCardDeck()
{
	if (_deck->size() == 0)
	{
		return NULL;
	}
	return _deck->pop_back();
}

Card* Game::drawCardDiscard()
{
	if (_discardPile->size() == 0)
	{
		return NULL;
	}
	return _discardPile->pop_back();
}	

Card* Game::peekDeck()
{
	if (_deck->empty())
	{
		return NULL;
	}
	return _deck->back();
}

void Game::discardCard(Card& card)
{
	_discardPile->push_back(&card);
}

Player* Game::currentPlayer() const
{
	return _players[_currentPlayer];
}

Player* Game::otherPlayer() const
{
	return _players[1 - _currentPlayer];
}


void Game::switchPlayer()
{
	_currentPlayer = _currentPlayer + 1 % 2;
	_otherPlayer = _otherPlayer + 1 % 2;

	_currentTurn += 1;
	if (_currentPlayer == 0)
		_currentRound += 1;
}

Game::~Game()
// Cleanup.
{
	delete _players[0];
	delete _players[1];
}