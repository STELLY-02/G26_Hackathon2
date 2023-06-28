#ifndef PRESANDTRASH_H
#define PRESIDENTGAME_H
#include "PLAYER.h"
#include "CARDDECK.h"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

class PresidentGame : Player{
private:
    Player* players;
    CardDeck* cardDeck;
    int numPlayers;
    int currentPlayer;
    bool roundFinished;
    string currentCard;
    int cardsDiscarded = 0;
    int previousCardCounter = 0;
    int consecutivePass = 0;
    int* ranking;
    int* playerOrder;
    int* winTime;

public:
    PresidentGame();
    ~PresidentGame();

    void SetPlayerNum(int);
    void SetGame();
    void SetRankingOrder();
    void SetPlayerName(int, string);
    void SetwinTime(int, int);
    void PrintWinTime();
    void StartNewGame();
    void StartGame();
    void PlayRounds();
    bool CheckRoundCompletion();
};
#endif
