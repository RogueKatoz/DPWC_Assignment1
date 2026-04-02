#include "Player.h"
#include "Card.h"
#include "Game.h"

Player::Player()
{
}

int Player::getScore()
{
	return 0;
}

int Player::getName()
{
	return 0;
}

void Player::playCard(Card* card, Game& game)
{
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
