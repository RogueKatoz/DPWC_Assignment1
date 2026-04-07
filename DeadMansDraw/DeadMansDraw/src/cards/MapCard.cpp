#include "cards/MapCard.h"
#include "Game.h"
#include "Player.h"

#include <algorithm>
#include <iostream>

MapCard::MapCard(int value) : Card(Map, value) {}

std::string MapCard::str() const
{
	return "Map(" + std::to_string(_value) + ")";
}

void MapCard::play(Game& game, Player& player)
// Draw 3 cards from the discard pile, pick one to add to play area, and discard the rest.
{
	CardCollection discardCards;
	for (int i = 0; i < 3; i++)
	{
		Card* drawnCard = game.drawCardDiscard();
		if (drawnCard != nullptr)
		{
			discardCards.push_back(drawnCard);
		}
	}
	
	if (discardCards.size() == 0)
	{
		std::cout << "\tNo cards in the discard. Play continues." << std::endl;
		return;
	}

	int maxChoice = discardCards.size();
	std::cout << "\tDraw 3 cards from the discard and pick one to add to the play area:" << std::endl;
	for (int i = 0; i < maxChoice; i++)
	{
		std::cout << "\t(" << i+1 << ") " << discardCards[i]->str() << std::endl;
	}

	int cardIndex = 0;
	while (cardIndex <= 0 || cardIndex > maxChoice)
	{
		std::cout << "\tWhich card do you pick? ";
		std::cin >> cardIndex;
		// Fix to clear cin and purge input buffer if input is invalid.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Take chosen card, discard rest, and play the card.
	Card* cardToPlay = (discardCards)[cardIndex-1];
	discardCards.erase(std::remove(discardCards.begin(), discardCards.end(), cardToPlay), discardCards.end());
	for (Card* card : discardCards)
	{
		game.discardCard(*card);
	}
	player.playCard(cardToPlay, game);
}
