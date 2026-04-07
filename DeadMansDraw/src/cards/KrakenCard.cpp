#include "KrakenCard.h"
#include <string>

KrakenCard::KrakenCard(int value)
{
	Card(Kraken, value);
}

std::string KrakenCard::str() const
{
	return "Kraken(" + std::to_string(_value) + ")";
}

void KrakenCard::play(Game& game, Player& player)
{
}
