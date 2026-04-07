#include "cards/MermaidCard.h"
#include "Game.h"
#include "Player.h"

#include <string>
#include <iostream>

MermaidCard::MermaidCard(int value) : Card(Mermaid, value) {}

std::string MermaidCard::str() const
{
	return "Mermaid(" + std::to_string(_value) + ")";
}

void MermaidCard::play(Game& game, Player& player)
{
	std::cout << "\tNo effect but Mermaids are worth more" << std::endl;
}
