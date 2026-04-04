#include "Player.h"
#include "Card.h"
#include "Game.h"

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
}

void Player::discardPlayedCards(Game& game)
{
}

void Player::printPlayedCards()
{
}

void Player::printBank()
{
}

Player::~Player()
{
}
