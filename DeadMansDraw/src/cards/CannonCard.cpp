#include "CannonCard.h"
#include <string>

CannonCard::CannonCard(int value)
{
	Card(Cannon, value);
}

std::string CannonCard::str() const
{
	return "Cannon(" + std::to_string(_value) + ")";
}

void CannonCard::play(Game& game, Player& player)
// If other player's bank has cards, steal the highest value card from suit of player's choice and discard it.
{	
	
}
