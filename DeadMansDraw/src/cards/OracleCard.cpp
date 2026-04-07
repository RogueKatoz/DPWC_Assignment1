#include "OracleCard.h"
#include <string>
#include <iostream>

OracleCard::OracleCard(int value) : Card(Oracle, value) {}

std::string OracleCard::str() const
{
	return "Oracle(" + std::to_string(_value) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
	Card* nextCard = game.peekDeck();
	if (nextCard == nullptr)
	{
		std::cout << "\tNo cards left in deck." << std::endl;
		return;
	}

	std::cout << "\tThe Oracle sees a " << nextCard->str() << std::endl;
}
