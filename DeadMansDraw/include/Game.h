#pragma once

#include "CardTypes.h"

class Player;

class Game {
private:
	Player* _players[2];
	CardCollection* _deck;
	CardCollection* _discardPile;
	int _currentRound;
	int _currentTurn;
	int _currentPlayer;

public:
	Game();

	void initialiseGame();
	void initialisePlayers();
	void createDeck();
	Card* createCard(CardType type, int value);
	void shuffleDeck() const;
	void startGame();
	bool endGame() const;
	void playTurn();
	bool promptDrawCard();
	Card* drawCardDeck();
	Card* drawCardDiscard();
	Card* peekDeck();
	void discardCard(Card& card);
	Player* currentPlayer() const;
	Player* otherPlayer() const;
	void switchPlayer();

	~Game();
};