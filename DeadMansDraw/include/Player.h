#pragma once


class Player;

class Player {
private:
	std::string _name;
	int _score = 0;
	CardCollection _playArea;
	CardCollection _bank;

public:

	Player();

	int getScore();
	int getName();

	void playCard(Card* card, Game& game);
	bool isBust();
	void bankPlayedCards();
	void discardPlayedCards(Game& game);
	void printPlayedCards();
	void printBank();

	~Player();
};