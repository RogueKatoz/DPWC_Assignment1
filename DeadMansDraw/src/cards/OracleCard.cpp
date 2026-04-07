#include "OracleCard.h"
#include <string>

OracleCard::OracleCard(int value)
{
	Card(Oracle, value);
}

std::string OracleCard::str() const
{
	return "Oracle(" + std::to_string(_value) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
}
