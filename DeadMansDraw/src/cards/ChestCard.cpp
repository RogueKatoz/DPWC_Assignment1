#include "cards/ChestCard.h"
#include "Game.h"
#include "Player.h"

#include <string>
#include <iostream>

ChestCard::ChestCard(int value) : Card(Chest, value) {}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(_value) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
	std::cout << "\tNo immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}

void willAddToBank(Game& game, Player& player)
{
	CardCollection* discardCards;
	for (int i = 0; i < 3; i++)
	{
		Card* drawnCard = game.drawCardDiscard();
		if (drawnCard != nullptr)
		{
			discardCards->push_back(drawnCard);
		}
	}

	std::cout << "\tChest and key activated. Added ";
	for (Card* card : *discardCards)
	{
		std::cout << card->str() << ", ";
		player.addToBank(card);
	}
	std::cout << "to your bank." << std::endl;
}
