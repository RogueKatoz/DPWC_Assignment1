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

void Player::printPlayedArea()
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

void Player::printCollection(const CardCollection cards)
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
			Card* highestCard; int highestValue = 0;
			for (Card* card : *cardsToPrint)
			{
				if (card->value() > highestValue)
				{
					highestCard = card;
					highestValue = card->value();
				}
			}
			std::cout << " " << highestCard->str();
		}
		std::cout << std::endl;
	}
}

bool Player::BankHasCards()
// Simply check whether or not the bank is empty.
{
	if (_bank->size() == 0)
	{
		return false;
	}
	else return true;
}


Card* Player::stealBankCard()
// List highest card of each type in bank, ask which to take, and return it, deleting it from the bank.
{
	// Check from highest value first.
	CardCollection* cardsToSteal;
	for (int i = 9, i > 0, i--)
	{
		for (Card* cardA : *_bank)
		{
			// If card is found of this value, check steal collection to see if card of same type already exists.
			if (card->value() == i)
			{
				int addCard = 1;
				for (Card* cardB : cardsToSteal)
				{
					if (cardA->type() == cardB->type())
						addCard = 0;
						break;
					}
				}

				if (addCard == 1)
					cardsToSteal->push_back(cardA);
			}
		}

	}

	// Print cards to steal.
	
	for (int i = 0; i < cardsToSteal->size(); i++)
	{
		std::cout << "\t(" << i+1 << ") " << (*cardsToSteal)[i]->str() << std::endl;
	}

	// Ask user which card to steal.
	int maxChoice = cardsToSteal->size();
	int cardIndex = 0;

	while (cardIndex > 0 && cardIndex <= maxChoice)
	{
		std::cout << "\tWhich card do you pick? ";
		std::cin >> cardIndex;
		std::cout << std::endl;
	}

	// Remove card from bank and return it.
	Card* cardToSteal = (*cardsToSteal)[cardIndex];
	_bank->erase(std::remove(_bank->begin(), bank->end(), cardToSteal), _bank->end());
	return cardToSteal;
}

void Player::addToPlayArea(Card* card)
// Manually add card to play area without playing it.
{
	_playArea->push_back(card);
}

void Player::addToBank(Card* card)
// Manually add single card to bank.
{
	_bank->push_back(card);
}

Player::~Player()
{
}
