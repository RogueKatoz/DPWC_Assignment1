#pragma once

class Game;

class Game {
private:
	Player* _players[2];
	CardCollection _deck;
	CardCollection _discardPile;
	int _currentRound;
	int _currentTurn;
	int _currentPlayer;
	int _otherPlayer;

public:
	Game();

	void initialiseGame();
	void initialisePlayers();
	void createDeck();
	void shuffleDeck() const;
	void startGame();

	bool gameEnd() const;
	void playTurn();
	bool promptDrawCard();
	Card* drawCard();
	void
	void discardCard(Card&);
	void switchPlayer();

	~Game();
};