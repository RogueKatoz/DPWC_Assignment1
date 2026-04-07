#pragma once

#include <CardTypes.h>

#include <string>
#include <vector>

class Game;
class Player;

class Card {
protected:
	CardType _type;
	int _value;

public:
	Card(CardType type, int value);
	virtual ~Card();

	const CardType& type() const;
	int value() const;
	virtual std::string str() const = 0;
	virtual void play(Game& game, Player& player) = 0;
	virtual void willAddToBank(Game& game, Player& player) = 0;
};