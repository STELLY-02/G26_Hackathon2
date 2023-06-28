#include "PRESIDENTGAME.h"
#include "PLAYER.h"
#include "CARDDECK.h"
#include <iostream>
using namespace std;

	class Player;

    PresidentGame::PresidentGame() : players(nullptr), currentPlayer(0), roundFinished(false) {}

    PresidentGame::~PresidentGame() {
        delete[] players;
    }

    void PresidentGame::SetPlayerNum(int num){
        numPlayers = num;
    }

    void PresidentGame::SetGame(){
        players = new Player[numPlayers];
        cardDeck = new CardDeck();
        ranking = new int[numPlayers];
        playerOrder = new int[numPlayers];
        playerName = new string[numPlayers];
        winTime = new int[numPlayers];
    }

    void PresidentGame::SetRankingOrder(){
        for(int i = 0;i < numPlayers;++i){
            playerOrder[i] = i;
            ranking[i] = i; // need modify
        }
    }

    void PresidentGame::SetPlayerName(int order, string name){
        playerName[order] = name;
    }

    void PresidentGame::SetwinTime(int order, int wins){
        winTime[order] = wins;
    }

    void PresidentGame::PrintWinTime(){
        for(int i = 0;i < numPlayers;++i){
            cout << "Player " << playerName[i] << " wins " << winTime[i] << "time(s)."<< endl;
        }
    }

    void PresidentGame::StartNewGame() {

        SetGame();

        for(int i = 0;i < numPlayers;++i){
            playerOrder[i] = i;
            ranking[i] = i;
            winTime[i] = 0;
            cout << "Player " << i+1 << "'s name: ";
            getline(cin >> ws, playerName[i]);
        }

        StartGame();
    }

    void PresidentGame::StartGame() {
        bool contFlg = true;
        do{
            cardDeck->GenerateShuffledDeck();
            cardDeck->DistributeDeck(players, numPlayers);

            currentPlayer = 0;
            roundFinished = false;
            currentCard = "0";
            PlayRounds();
            int gameType;
            cout<<"========================="<<endl;
            cout << "1.Continue the game" << endl;
            cout << "2.Save the game" << endl;
            cout << "3.Quit" << endl;
            cout<<"========================="<<endl;
            cout << "Choose: " << endl;
            cin >> gameType;
            if(gameType == 1){
                for(int i = 0;i < numPlayers;++i){
                    playerOrder[i] = ranking[i];
                }
                delete players;
                cardDeck = new CardDeck();
                players = new Player[numPlayers];
            }
            else if(gameType == 2){
                string fileName;
                cout << "File name (without typing .txt): ";
                getline(cin >> ws, fileName);
                ofstream ofs(fileName + ".txt");
                ofs << numPlayers << endl;
                for(int i = 0;i < numPlayers;++i){
                    ofs << playerName[ranking[i]] << " " << winTime[ranking[i]] << endl;
                }
                ofs.close();
                
                contFlg = false;
                cout << "Game Over" << endl;
            }
            else{
                contFlg = false;
                cout << "Game Over" << endl;
            }
        }while(contFlg);
        
        system("pause");
    }

    void PresidentGame::PlayRounds() {
        bool nextRoundFlg = false;
        bool finishPlayer[numPlayers] = {false};
        int finPlayerNum = 0;
        while (!roundFinished) {
            system("cls");
            cout << "Please make sure there is no other player looking on ur screen." << endl;
            system("pause");
			cout<<"====================================================================================="<<endl;
            cout << "Card on the table:  " << currentCard  << endl;
            cout<<"====================================================================================="<<endl;
            cout << "Player " << playerName[playerOrder[currentPlayer]] << "'s Hand: ";
            players[playerOrder[currentPlayer]].PrintHand();
            cout<<endl;

            string cardsToDiscard;
            bool validDiscard = false;
            while (!validDiscard) {
                cout << "Enter the cards you want to discard (space-separated for more than 1 card) or type 'pass' to skip your turn: ";
                getline(cin >> ws, cardsToDiscard);

                if(cardsToDiscard == "pass"){
                    cout << "Player " << playerName[playerOrder[currentPlayer]]  << " pass.\n";
                    consecutivePass++;
                    nextRoundFlg = true;
                    validDiscard = true;
                    if(consecutivePass >= numPlayers - finPlayerNum - 1){
                        currentCard = "0";
                        previousCardCounter = 0;
                        consecutivePass = 0;
                        cout<<"Every player has passed"<<endl;
                    	cout<<"====================================================================================="<<endl;
                    	cout<<"                                  Round cleared"<<endl;
                    	cout<<"====================================================================================="<<endl;
                        cout<<"You now can throw any card that you want."<<endl;
                    }
                    continue;
                }
                else{
                    consecutivePass = 0;
                }
                
                istringstream iss1(cardsToDiscard);
                string cardValue;
                if (!(iss1 >> cardValue)) {
                    validDiscard = false;
                    cout << "Invalid input! Please enter at least one card.\n\n";
                    continue;
                }

                validDiscard = true;
                //card the second and so forth, whether it is contain in the deck
                do
                {
                    if (!players[playerOrder[currentPlayer]].HasCard(cardValue)) {
                        validDiscard = false;
                        cout << "You don't have the card \"" << cardValue << "\"! Try again.\n\n";
                        break;
                    }
                } while (iss1 >> cardValue);

                if (!validDiscard) {
                    continue;
                }

                if (!players[playerOrder[currentPlayer]].HasSameRank(cardsToDiscard)) {
                    validDiscard = false;
                    cout << "The cards must have the same rank! Try again.\n\n";
                    continue;
                }

                if (!players[playerOrder[currentPlayer]].HasDiffSuit(cardsToDiscard)) {
                    validDiscard = false;
                    cout << "The cards are repeated! Try again.\n\n";
                    continue;
                }

                if(cardsToDiscard.substr(0, 1) == "2"){
                    currentCard = "0";
                    previousCardCounter = 0;
                    istringstream iss5(cardsToDiscard);
                    string cardValue;
                    //discard one card by one card
                    while (iss5 >> cardValue) {
                        players[playerOrder[currentPlayer]].RemoveCard(cardValue);
                    }
                    cout<<"====================================================================================="<<endl;
                    cout<<"                                  Round cleared"<<endl;
                    cout<<"====================================================================================="<<endl;
                    if(players[playerOrder[currentPlayer]].IsEmpty()){
                        ranking[finPlayerNum] = playerOrder[currentPlayer];
                        finishPlayer[playerOrder[currentPlayer]] = true;
                        finPlayerNum++;
                        cout << "Player " << playerName[playerOrder[currentPlayer]]  << " finish.\n\n";
                        nextRoundFlg = true;
                        validDiscard = true;
                    }
                    else{
                        cout<<"You now can throw any card that you want."<<endl<<endl;
                        validDiscard = false;
                    }
                    continue;
                }

  

                istringstream iss0(cardsToDiscard);
                int currentCardCounter=0;
                string temp;
                while(iss0>>temp){
                	currentCardCounter++;
				}
				char throwCard = cardsToDiscard[0];
				//if less, invalid. If equal, continue. If larger, any value
				if (currentCardCounter<previousCardCounter){
                    validDiscard = false;
                    cout<<"!! ERROR: Too less card !!"<<endl;
                    cout<<"You must throw same number or more cards!"<<endl<<endl;
                    continue;	
				}
				else if (currentCardCounter>previousCardCounter){

					previousCardCounter=currentCardCounter;
				}
				else{
                    istringstream iss3(currentCard);
                    string current;
                    iss3 >> current;
                    int cur_val = cardDeck->GetValueOfStr(current.substr(0, current.length()-1));

                    istringstream iss4(cardsToDiscard);
                    string discard;
                    iss4 >> discard;
                    int dis_val = cardDeck->GetValueOfStr(discard.substr(0, discard.length()-1));

                    // current value is larger than the card that player selected
                    if(cur_val > dis_val){
                        validDiscard = false;
                        cout<<"!! ERROR: Value too small !!"<<endl;
                        cout << "Your card must be larger or equal to " << currentCard << endl<<endl;
                        continue;
                    }
					previousCardCounter=currentCardCounter;
				}
            }

            if(nextRoundFlg){
                if(finPlayerNum >= numPlayers - 1){
                    for(int i = 0;i < numPlayers;++i){
                        if(finishPlayer[playerOrder[i]] == false){
                            ranking[finPlayerNum] = playerOrder[i];
                            break;
                        }
                    }
                    break;
                }
                for(int i = 0;i < numPlayers;++i){
                    currentPlayer = (currentPlayer + 1) % numPlayers;
                    if(!finishPlayer[playerOrder[currentPlayer]]){
                        break;
                    }
                }
                nextRoundFlg = false;
                continue;
            }

            currentCard = cardsToDiscard;

            istringstream iss2(cardsToDiscard);
            string cardValue;
            cardsDiscarded=0;
            //discard one card by one card
            while (iss2 >> cardValue) {
                players[playerOrder[currentPlayer]].RemoveCard(cardValue);
                cardsDiscarded++;
            }
            cout << "Player " << playerName[playerOrder[currentPlayer]]  << " discarded " << cardsDiscarded << " card(s).\n\n";
            if(players[playerOrder[currentPlayer]].IsEmpty()){
                ranking[finPlayerNum] = playerOrder[currentPlayer];
                finishPlayer[playerOrder[currentPlayer]] = true;
                finPlayerNum++;
                cout<<"====================================================================================="<<endl;
        		cout << "\t\tPlayer " << playerName[playerOrder[currentPlayer]]  << " finish.\n";
        		cout<<"====================================================================================="<<endl;
                if(finPlayerNum >= numPlayers - 1){
                    for(int i = 0;i < numPlayers;++i){
                        if(finishPlayer[playerOrder[i]] == false){
                            ranking[finPlayerNum] = playerOrder[i];
                            break;
                        }
                    }
                    break;
                }
            }
            for(int i = 0;i < numPlayers;++i){
                currentPlayer = (currentPlayer + 1) % numPlayers;
                if(!finishPlayer[playerOrder[currentPlayer]]){
                    break;
                }
            }
            //currentPlayer = (currentPlayer + 1) % numPlayers;
            //roundFinished = CheckRoundCompletion();
        }

        winTime[ranking[0]]++;
        cout<<"====================================================================================="<<endl;
        cout<<"                                  Round finished"<<endl;
        cout<<"====================================================================================="<<endl;
        cout<<"Congratulations: "<<endl;
        cout << "President is Player " << ranking[0] + 1 << "." << endl<<endl;
        cout<<"Unfortunately: "<<endl;
        cout << "Trash is Player " << ranking[numPlayers-1] + 1 << "." << endl;
    }

    bool PresidentGame::CheckRoundCompletion() {
        for (int i = 0; i < numPlayers; ++i) {
            if (!players[i].IsEmpty()) {
                return false;
            }
        }
        return true;
    }
