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
{
	if (isBust() == 1) discardPlayedCards(game);

	card->play(game, *this);

}

bool Player::isBust()
{
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
