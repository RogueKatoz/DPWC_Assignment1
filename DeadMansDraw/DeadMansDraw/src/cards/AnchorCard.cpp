#include "cards/AnchorCard.h"
#include "Game.h"
#include "Player.h"

#include <iostream>
#include <string>

AnchorCard::AnchorCard(int value) : Card(Anchor, value) {}

std::string AnchorCard::str() const
{
	return "Anchor(" + std::to_string(_value) + ")";
}

void AnchorCard::play(Game& game, Player& player)
{
	std::cout << "\tEffect not yet implemented." << std::endl;
}
