#include "cards/KrakenCard.h"
#include "Game.h"
#include "Player.h"

#include <string>
#include <iostream>

KrakenCard::KrakenCard(int value) : Card(Kraken, value) {}

std::string KrakenCard::str() const
{
	return "Kraken(" + std::to_string(_value) + ")";
}

void KrakenCard::play(Game& game, Player& player)
// Draw up to three cards and play them one at a time.
{
	std::cout << "\tDraw 3 cards from the deck and play each:" << std::endl;
	
	for (int i = 0; i < 3; i++)
	{
		Card* drawnCard = game.drawCardDeck();
		if (drawnCard != nullptr && player.isBust() == 0)
		{
			player.playCard(drawnCard, game);
		}
	}
}
