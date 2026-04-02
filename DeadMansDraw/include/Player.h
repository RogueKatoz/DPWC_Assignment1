#pragma once
#include <iostream>

class Player;

class Player {
private:
	std::string _name;
	int _score;
	CardCollection _playArea;
	CardCollection _bank;

public:

	Player();

	int calculateScore();
	std::string getName() const;

	void playCard(Card* card, Game& game);
	bool isBust();
	void bankPlayedCards();
	void discardPlayedCards(Game& game);
	void printPlayedCards();
	void printBank();

	~Player();
};