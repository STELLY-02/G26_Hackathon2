#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "PRESIDENTGAME.h"
using namespace std;

int main() {
    cout<<"\t\t====================================================================================="<<endl;
    cout<<"\t\t*************************************************************************************"<<endl;
    cout<<"\t\t                       WELCOME TO PRESIDENT(SCUM) GAME!"<<endl;
    cout<<"\t\t*************************************************************************************"<<endl;
    cout<<"\t\t====================================================================================="<<endl<<endl;
    cout<<"\t\tGame rules are as follow:"<<endl<<endl;
    cout<<"\t\t1. Fisrt player are free to discard any card"<<endl;
    cout<<"\t\t2. The card(s) can be single, pair, triple or bombs(quadruple)"<<endl;
    cout<<"\t\t3. The subsequent players has to discard a card that is bigger than the previous card"<<endl;
    cout<<"\t\t                                     OR"<<endl;
    cout<<"\t\t   You can overtake the round by outputting more cards (single< pairs< triple< bombs)"<<endl;
    cout<<"\t\t   regardless of the value as long as you have more card"<<endl;
    cout<<"\t\t4. You can key in pass to skip the round"<<endl<<endl;
    cout<<"\t\t**"<<endl;
    cout<<"\t\tGame is never interesting without twist"<<endl;
    cout<<"\t\t**"<<endl;
    cout<<"\t\tThe card 2 is the power card. You may discard 2 to clear the round and discard any card"<<endl;
    cout<<"\t\tfollowing that!"<<endl<<endl;
    cout<<"\t\tSo, Are you ready to play the game (`O ´)/..... "<<endl;
    cout<<"\t\tBe the fastest to shed all your card and be the President among your friend! Y_(^-^)_Y"<<endl;
    cout<<"\t\tThe last friend will be the scum, and feel free to instruct him to do anything ?(^o^ )??"<<endl<<endl;
    cout<<"Press enter to start the game!"<<endl;
    char c;
    cin.get(c);
    int gameType;
    cout << "*******************"<<endl;
    cout << "1.Start a new game" << endl;
    cout << "2.Load a game" << endl;
    cout << "3.Quit" << endl;
    cout << "*******************"<<endl;
    cout << "Choose: ";
    cin >> gameType;
    if(gameType == 1){
        int playerNum;
        cout << "Enter number of players: ";
        cin >> playerNum;
        cin.ignore();
        while(playerNum<4 && playerNum>7){
        	cout<<"This game is recommended to play between 4-7 people"<<endl;
        	cout<<"Enter again the number of players";
        	cin>> playerNum;
		}
        PresidentGame game;
        game.SetPlayerNum(playerNum);
        game.StartNewGame();
    }
    else if(gameType == 2){
        PresidentGame game;
        string fileName;
        cout << "File Name (without typing .txt): ";
        cin >> fileName;
        ifstream file(fileName + ".txt");
        string readStr;
        int nowInd = 0;
        while (getline(file, readStr))
        {
            if(nowInd == 0){
                game.SetPlayerNum(stoi(readStr));
                game.SetGame();
                game.SetRankingOrder();
            }
            else{
                istringstream issR(readStr);
                string cur;
                issR >> cur;
                game.SetPlayerName(nowInd-1, cur);
                issR >> cur;
                game.SetwinTime(nowInd-1, stoi(cur));
            }
            nowInd++;
        }
        cout << "Load Game Complete." << endl;
        game.PrintWinTime();
        game.StartGame();
    }
    else{
        cout << "Quit" << endl;
    }

    system("pause");
    return 0;
}

