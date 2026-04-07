#include "HookCard.h"
#include <string>
#include <iostream>

HookCard::HookCard(int value) : Card(Hook, value) {}

std::string HookCard::str() const
{
	return "Hook(" + std::to_string(_value) + ")";
}

void HookCard::play(Game& game, Player& player)
{
	if (game->otherPlayer()->bankHasCards() == 0)
	{
		std::cout << "No cards in your bank. Play continues." << std::endl;
		return;
	}

	std::cout << "\tSelect a highest-value card from any of the suits in your Bank:" << std::endl;
	player->playCard(player->stealBankCard(), game);
}
