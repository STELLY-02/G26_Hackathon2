#include "PLAYER.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

Player::Player() : head(nullptr), size(0) {}

void Player::AddCard(const string& cardValue) {
    CardNode* newNode = new CardNode(cardValue);

    int nowV = GetValueOfStr(cardValue.substr(0, cardValue.length()-1));
    if (head == nullptr || nowV < GetValueOfStr((head->value).substr(0, (head->value).length()-1))) {
        newNode->next = head;
        head = newNode;
    } else {
        CardNode* currentNode = head;
        while (currentNode->next != nullptr && GetValueOfStr((currentNode->next->value).substr(0, (currentNode->next->value).length()-1)) < nowV) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    size++;
}

void Player::RemoveCard(const string& cardValue) {
    if (head == nullptr)
        return;

    if (head->value == cardValue) {
        CardNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    CardNode* current = head;
    while (current->next != nullptr) {
        if (current->next->value == cardValue) {
            CardNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
}

void Player::RemoveCards(const string& cardValue) {
    while (HasCard(cardValue)) {
        RemoveCard(cardValue);
    }
}

void Player::PrintHand() const {
    CardNode* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

bool Player::HasCard(const string& cardValue) const {
    CardNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->value == cardValue) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}
    
//check whether the chosen cards are having same rank
bool Player::HasSameRank(const string& cardValue) const {
    istringstream iss(cardValue);
    string singleCard;
    string firstRank;

    if (!(iss >> singleCard)) {
        return true; // No cards provided, consider it as a valid case
    }

    firstRank = singleCard.substr(0, singleCard.length() - 1); // Extract the rank from the first card

    while (iss >> singleCard) {
        string rank = singleCard.substr(0, singleCard.length() - 1); // Extract the rank from the current card
        if (rank != firstRank) {
            return false; // Card has a different rank than the first card
        }
    }

    return true; // All cards have the same rank
}

//check whether the chosen cards are having different suits
bool Player::HasDiffSuit(const string& cardValue) const {
    istringstream iss(cardValue);
    string singleCard;
    char suitStr[3];
    int suitInd = 0;

    if (!(iss >> singleCard)) {
        return true; // No cards provided, consider it as a valid case
    }

    suitStr[suitInd++] = singleCard[singleCard.length() - 1]; // Extract the suit from the first card

    while (iss >> singleCard) {
        char suit = singleCard[singleCard.length() - 1]; // Extract the suit from the current card
        for(int i = 0;i < suitInd;++i){
            if(suit == suitStr[i]){
                return false; // Card has the same suit
            }
        }
        suitStr[suitInd++] = suit;
    }

    return true; // All cards have the different suit
}

bool Player::IsEmpty() const {
    return head == nullptr;
}

int Player::GetSize() const {
    return size;
}

int Player::GetValueOfStr(string rank){
    const string ranksOrder[] = {"0", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i = 0;i < 14;++i){
        if(rank == ranksOrder[i]){
            return i;
        }
    }
    return -1;
}
