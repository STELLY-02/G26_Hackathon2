#ifndef CARDDECK_H
#define CARDDECK_H
#include "PLAYER.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>

class CardDeck {
    private:
        struct Card {
            string value;
            Card* next;
        };

        Card* head;
        int deckSize;

    public:
        CardDeck();
        ~CardDeck();
        
        void GenerateShuffledDeck();
        void  DistributeDeck(Player*, int);
        int GetValueOfStr(string);    
};
#endif
