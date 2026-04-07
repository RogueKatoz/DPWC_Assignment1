#include "SwordCard.h"
#include <string>

SwordCard::SwordCard(int value)
{
	Card(Sword, value);
}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(_value) + ")";
}

void SwordCard::play(Game& game, Player& player)
// If other player's bank has cards, steal the highest value card from suit of player's choice and place it into play area.
{
	if (game->otherPlayer()->bankHasCards() == 0)
	{
		std::cout << "No cards in other player's bank. Play continues." << std::endl;
		return;
	}

	std::cout << "\tShoot the top card of any suit from the other player's Bank into the Discard Pile:" << std::endl;
	Card* cardToDiscard = game->otherPlayer()->stealBankCard();
	game->discardCard(*cardToDiscard);
}