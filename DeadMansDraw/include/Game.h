#pragma once

class Game;

class Game {
private:
	Player[2] _players;
	CardCollection _deck;
	CardCollection _discardPile;
	int _currentRound;
	int _currentTurn;

public:
	Game();
	~Game();

	void initialiseGame();
	void initialisePlayers();
	void createDeck();
	void shuffleDeck();
	void startGame();
	void playTurn();
	Card* drawCard();
	void discardCard(Card&);
	void switchPlayer();
	void endGame();
};