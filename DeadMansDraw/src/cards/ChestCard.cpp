#include "ChestCard.h"
#include <string>

ChestCard::ChestCard(int value)
{
	Card(Chest, value);
}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(_value) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
}
