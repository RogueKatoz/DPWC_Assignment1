#include "Game.h"
#include "Player.h"
#include "Card.h"
#include "game_title.h"

#include "cards/AnchorCard.h"
#include "cards/CannonCard.h"
#include "cards/ChestCard.h"
#include "cards/KeyCard.h"
#include "cards/SwordCard.h"
#include "cards/HookCard.h"
#include "cards/OracleCard.h"
#include "cards/MapCard.h"
#include "cards/MermaidCard.h"
#include "cards/KrakenCard.h"

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
				_deck->push_back(createCard(type, val));
			}
		}
		else
		{
			for (int val = 2; val <= 7; val++)
			{
				_deck->push_back(createCard(type, val));
			}
		}
	}
}

Card* Game::createCard(CardType type, int value)
{
	switch (type)
	{
		case Cannon:
			return new CannonCard(value);
		case Chest:
			return new ChestCard(value);
		case Key:
			return new KeyCard(value);
		case Anchor:
			return new AnchorCard(value);
		case Sword:
			return new SwordCard(value);
		case Hook:
			return new HookCard(value);
		case Oracle:
			return new OracleCard(value);
		case Map:
			return new MapCard(value);
		case Mermaid:
			return new MermaidCard(value);
		case Kraken:
			return new KrakenCard(value);
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
	std::cout << _players[_currentPlayer]->getName() << "'s turn." << std::endl;
	_players[_currentPlayer]->printBank();
	while (1)
	{
		// Draw and play card if deck is not empty.
		Card* cardToPlay = drawCard();
		if (cardToPlay == NULL) break;
		_players[_currentPlayer]->playCard(cardToPlay, this);

		// Check if player is bust and break, or ask for another card.
		if (_players[_currentPlayer]->isBust() == 1) break;

		_players[_currentPlayer]->printPlayArea();
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
	Card* drawnCard = _deck->back();
	_deck->pop_back();
	return drawnCard;
}

Card* Game::drawCardDiscard()
{
	if (_discardPile->size() == 0)
	{
		return NULL;
	}
	Card* drawnCard = _discardPile->back();
	_discardPile->pop_back();
	return drawnCard;
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
	
	for (Card* card : *_deck)
		delete card;
	delete _deck;

	for (Card* card : *_discardPile)
		delete card;
	delete _discardPile;
}