#include "cards/CannonCard.h"
#include "Game.h"
#include "Player.h"

#include <string>
#include <iostream>

CannonCard::CannonCard(int value) : Card(Cannon, value) {}

std::string CannonCard::str() const
{
	return "Cannon(" + std::to_string(_value) + ")";
}

void CannonCard::play(Game& game, Player& player)
// If other player's bank has cards, steal the highest value card from suit of player's choice and discard it.
{	
	if (game->otherPlayer()->bankHasCards() == 0)
	{
		std::cout << "No cards in other player's bank. Play continues." << std::endl;
		return;
	}

	std::cout << "\tShoot the top card of any suit from the other player's Bank into the Discard Pile:" << std::endl;
	Card* cardToDiscard = game->otherPlayer()->stealBankCard();
	game->discardCard(*cardToDiscard);
	std::cout << "\t You shoot the " << cardToDiscard->str() << " out of the other player's Bank" << std::endl;
}
