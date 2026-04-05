#include "Player.h"
#include "Card.h"
#include "Game.h"

#include <algorithm>

Player::Player()
{
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue",
	"Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];

	_score = 0;
	_playArea = new CardCollection;
	_bank = new CardCollection;
}

int Player::calculateScore()
{
	int score = 0;
	if (_bank->size() != 0)
	{
		for (CardType type : CARD_TYPES)
		{
			int highestValue;
			for (Card* card : *_bank)
			{
				if (card->type() == type && card->value() > highestValue)
				{
					highestValue = card->value();
				}
			}
			score += highestValue;
		}
	}
	return score;
}

std::string Player::getName() const
{
	return _name;
}

void Player::playCard(Card* card, Game& game)
// Add card to play area, then play effect if not bust.
{
	_playArea->push_back(card);
	if (isBust() == 1)
	{
		discardPlayedCards(game);
	} else card->play(game, *this);

	// Check if bust again after card has been played.
	if (isBust() == 1) discardPlayedCards(game);
}

bool Player::isBust()
// Go through play area cards and return true if two of the same suit exist.
{
	for (Card* cardA : *_playArea)
	{
		for (Card* cardB : *_playArea)
		{
			if (cardA != cardB && cardA->type() == cardB->type())
			{
				return true;
			}
		}
	}
	return false;
}

void Player::bankPlayedCards()
{
	while (_playArea->size() > 0)
	{
		_bank->push_back(_playArea->back());
		_playArea->pop_back();
	}
}

void Player::discardPlayedCards(Game& game)
{
	while (_playArea->size() > 0)
	{
		game.discardCard(*(_playArea->back()));
		_playArea->pop_back();
	}
}

void Player::printPlayedCards()
{
	std::cout << _name << "'s Play Area:" << std::endl;
	printCollection(*_playArea);
	std::cout << std::endl;
}

void Player::printBank()
{
	std::cout << _name << "'s Bank:" << std::endl;
	std::cout << "| Score: " << calculateScore() << std::endl;
}

void printCollection(const CardCollection cards)
// Go through each type of card present in play area/bank and print in descending order.
{
	for (CardType typetoPrint : CARD_TYPES)
	{
		// Get all cards of this type.
		CardCollection* cardsToPrint;
		for (Card* card : cards)
		{
			if (card->type() == typetoPrint)
			{
				cardsToPrint->push_back(card);
			}
		}
		if (cardsToPrint->size() == 0) continue;

		// Print all cards of this type in descending order of value.
		while (cardsToPrint->size() != 0)
		{
			Card* highestCard;
			for (Card* card : *cardsToPrint)
			{
				if (card->value() > highestCard->value())
				{
					highestCard = card;
				}
			}
			std::cout << " " << highestCard->str();
		}
		std::cout << std::endl;
	}
}	

Player::~Player()
{
}
