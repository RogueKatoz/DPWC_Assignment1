#include "cards/SwordCard.h"
#include "Game.h"
#include "Player.h"

#include <string>
#include <iostream>

SwordCard::SwordCard(int value) : Card(Sword, value) {}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(_value) + ")";
}

void SwordCard::play(Game& game, Player& player)
// If other player's bank has cards, steal the highest value card from suit of player's choice and place it into play area.
{
	if (game.otherPlayer()->bankHasCards() == 0)
	{
		std::cout << "No cards in other player's bank. Play continues." << std::endl;
		return;
	}

	std::cout << "\tSteal the top card of any suit from the other player's Bank into your Play Area:" << std::endl;
	player.playCard(game.otherPlayer()->stealBankCard(), game);
}