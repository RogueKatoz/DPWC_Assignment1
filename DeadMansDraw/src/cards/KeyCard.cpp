#include "KeyCard.h"
#include <string>

KeyCard::KeyCard(int value)
{
	Card(Key, value);
}

std::string KeyCard::str() const
{
	return "Key(" + std::to_string(_value) + ")";
}

void KeyCard::play(Game& game, Player& player)
{
}
