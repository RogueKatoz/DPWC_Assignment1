#include "Card.h"
#include "Game.h"
#include "Player.h"

Card::Card(CardType type, int value)
{
	_type = type;
	_value = value;
}

Card::~Card()
{
}

const CardType& Card::type() const
{
	return _type;
}

int Card::value() const
{
	return _value;
}

void Card::willAddToBank(Game& game, Player& player)
{
}
