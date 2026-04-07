#include "cards/KeyCard.h"
#include "Game.h"
#include "Player.h"

#include <string>
#include <iostream>

KeyCard::KeyCard(int value) : Card(Key, value) {}

std::string KeyCard::str() const
{
	return "Key(" + std::to_string(_value) + ")";
}

void KeyCard::play(Game& game, Player& player)
{
	std::cout << "\tNo immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}
