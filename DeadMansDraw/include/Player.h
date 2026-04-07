#pragma once

#include "CardTypes.h"
#include <string>

class Game;

class Player {
private:
	std::string _name;
	int _score;
	CardCollection* _playArea;
	CardCollection* _bank;

public:

	Player();

	int calculateScore();
	std::string getName() const;

	void playCard(Card* card, Game& game);
	bool isBust();
	bool playAreaContains(CardType type);
	void bankPlayedCards(Game& game);
	void discardPlayedCards(Game& game);
	void printPlayArea() const;
	void printBank();
	void printCollection(const CardCollection& cards) const;
	bool bankHasCards() const;
	Card* stealBankCard();
	void addToPlayArea(Card* card);
	void addToBank(Card* card);

	~Player();
};