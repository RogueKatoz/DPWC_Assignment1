#pragma once

#include <vector>
class Card;

typedef std::vector<Card*> CardCollection;

enum CardType {
	Cannon, 
	Chest, 
	Key, 
	Anchor, 
	Sword, 
	Hook, 
	Oracle, 
	Map, 
	Mermaid, 
	Kraken 
};

// Extra reusable list for iterating over all card types.
constexpr CardType CARD_TYPES[] = { 
	Cannon, 
	Chest, 
	Key, 
	Anchor, 
	Sword, 
	Hook, 
	Oracle, 
	Map, 
	Mermaid, 
	Kraken 
};