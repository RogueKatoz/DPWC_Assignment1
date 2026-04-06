#include "CannonCard.h"
#include <string>

CannonCard::CannonCard(int value)
{
	Card(Cannon, value);
}

std::string CannonCard::str() 
{
	return "Cannon(" + std::to_string(_value) + ")";
}

void CannonCard::play(Game& game, Player& player)
{

}
