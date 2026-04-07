#include "SwordCard.h"
#include <string>

SwordCard::SwordCard(int value)
{
	Card(Sword, value);
}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(_value) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
}
