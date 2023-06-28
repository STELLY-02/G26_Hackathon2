#include "CARDDECK.h"
#include "PLAYER.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

CardDeck::CardDeck() {
    deckSize = 52;
    head = nullptr;
}

CardDeck::~CardDeck() {
    Card* cardPtr = head;
    while (cardPtr != nullptr) {
        Card* temp = cardPtr;
        cardPtr = cardPtr->next;
        delete temp;
    }
}

void CardDeck::GenerateShuffledDeck() {
    const string suits[] = {"!", "@", "#", "$"};
    const string ranks[] = {"A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    head = nullptr;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            Card* newCard = new Card;
            newCard->value = ranks[j] + suits[i];
            newCard->next = nullptr;

            if (head == nullptr) {
                head = newCard;
            } else {
                Card* cardPtr = head;
                while (cardPtr->next != nullptr) {
                    cardPtr = cardPtr->next;
                }
                cardPtr->next = newCard;
            }
        }
    }

    srand(time(nullptr));
    Card* cardPtr = head;
    for (int i = deckSize - 1; i > 0; --i) {
        int j = rand() % (i + 1);

        Card* ithCard = cardPtr;
        Card* jthCard = cardPtr;
        for (int k = 0; k < i; ++k) {
            ithCard = ithCard->next;
        }
        for (int k = 0; k < j; ++k) {
            jthCard = jthCard->next;
        }

        swap(ithCard->value, jthCard->value);
    }
}

void CardDeck::DistributeDeck(Player* players, int numPlayers) {
    int cardsPerPlayer = deckSize / numPlayers;

    Card* currCard = head;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < cardsPerPlayer; j++) {
            players[i].AddCard(currCard->value);
            currCard = currCard->next;
        }
    }

    while (currCard != nullptr) {
        Card* nextCard = currCard->next;
        delete currCard;
        currCard = nextCard;
    }
    head = nullptr;
    deckSize = 0;
}

int CardDeck::GetValueOfStr(string rank){
    const string ranksOrder[] = {"0", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i = 0;i < 14;++i){
        if(rank == ranksOrder[i]){
            return i;
        }
    }
        return -1;
}
