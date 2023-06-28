#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Player {
private:
    struct CardNode {
        string value;
        CardNode* next;

        CardNode(const string& value) : value(value), next(nullptr) {}
    };

    CardNode* head;
    int size;

protected:
    string *playerName;

public:
    Player();

    void AddCard(const string&);
    void RemoveCard(const string&);
    void RemoveCards(const string&);
    void PrintHand() const;
    bool HasCard(const string&) const;
    bool HasSameRank(const string&) const;
    bool HasDiffSuit(const string&) const;
    bool IsEmpty() const;
    int GetSize() const;
    int GetValueOfStr(string);
};
#endif
