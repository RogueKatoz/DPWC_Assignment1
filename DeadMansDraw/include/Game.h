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
	void shuffleDeck() const;
	void startGame();
	bool gameEnd() const;
	void playTurn();
	Card* drawCard();
	v1oid discardCard(Card&);
	void switchPlayer();

	~Game();
};