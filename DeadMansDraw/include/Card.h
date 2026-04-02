#pragma once

#include "Game.h"
#include "Player.h"

#include <vector>

class Card;
typdef std::vector<Card*> CardCollection;

enum CardType {Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken};

class Card {
protected:
	CardType _type;
	int _value;

public:
	const CardType& type() const;
	int value();
	virtual std::string str() const = 0;
	virtual void play(Game& game, Player& player) = 0;
	virtual void willAddToBank(Game& game, Player& player) = 0;
};