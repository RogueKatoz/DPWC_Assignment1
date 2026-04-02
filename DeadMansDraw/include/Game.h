#pragma once

class Game;

class Game {
private:
	Player* _players[2];
	CardCollection _deck;
	CardCollection _discardPile;
	int _currentRound;
	int _currentTurn;

public:
	Game();

	void initialiseGame();
	void initialisePlayers();
	void createDeck();
	void shuffleDeck();
	void startGame();
	void playTurn();
	Card* drawCard();
	void discardCard(Card&);
	void switchPlayer();

	~Game();
};