#include<iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "functionused.h"
#define S   "\xE2\x99\xA0" // For printing out the suit of the card
#define C   "\xE2\x99\xA3"
#define H   "\xE2\x99\xA5"
#define D   "\xE2\x99\xA6"
using namespace std;

string Suit[] = { S,H,C,D };
string Num[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" }; // For the card data gathering
int card1, card2, card3, card4;

void Send_Card(vector<string>& computer, CardResult& result);
int Result(int i, int NumRaise, char a, int PlayerCard[], int CsCard[], vector<string>& computer);
char computer1(int& rounds, int CsCard[]);

int main()
{
    CardResult result;
    vector<string> computer;
    cout << "Welcome to the Six-Card challenge:)" << endl;
    cout << "Your initial fund: 200 HKD" << endl;
    cout << "You will have a initial cost of 10 HKD to play each ground" << endl;
    cout << "Please press 'Y' to start the game: " << endl; // Make the basic preparation to start the game.
    char y, x, z;
    int Fund;
    char filename[30] = "fund.txt";
    ifstream fin;
    fin.open(filename);
    if (fin.fail())
    {
        cout << "Error in the file opening" << endl;
        exit(1);
    }
    fin >> Fund;
    fin.close();
    int NumRound = 1;
    int PlayerCard[6];
    int CsCard[6];
    int changeFund;
    cin >> y; // Let the player type to begin the game.
    while (Fund > 9)
    { // If the player do not have enough money to begin a new round, the game will end.
        while (y != 'N') // If the player types "N", the game will end.
        {
            Fund = Fund - 10;
            cout << "Currently you have fund " << Fund << " HKD" << endl;
            int NumRaise = 0;
            int i;
            if (NumRound % 2 == 1) // Determine who will start to decide to raise or not. The player and the computer will do this by turns.
            {
                for (i=0;i<3; i++)
                {
                    Send_Card(computer, result);
                    PlayerCard[i*2] = result.a;
                    PlayerCard[i*2+1] = result.b;
                    CsCard[i*2] = result.c;
                    CsCard[i*2+1] = result.d; // To get the cards' points and record them.
                    cout << "You can choose whether you want to Raise or not." << endl;
                    cout << "Press 'c' to further Raise 10 HKD and 's' not to Raise" << endl;
                    cin >> x;// Let the player to determine the next move
                    if (x == 'c')
                    {
                        Fund = Fund - 10;
                        cout << "Currently you have fund " << Fund << " HKD" << endl;
                        NumRaise++;
                    }
                    else
                    {
                        Fund = Fund + 10;
                        break;
                    }
                    char a = computer1(i, CsCard);
                    if (a == 'c')
                    {
                        NumRaise++;
                    }
                    else
                    {
                        NumRaise++;
                        break;
                    }
                }
                changeFund = Result(i, NumRaise, x, PlayerCard, CsCard, computer); // Calculate the money changed in this round and record it.
            }
            else
            {
                int j;
                for (j=0;j<3;j++)
                {
                    Send_Card(computer, result);
                    PlayerCard[j*2] = result.a;
                    PlayerCard[j*2+1] = result.b;
                    CsCard[j*2] = result.c;
                    CsCard[j*2+1] = result.d;
                    char z = computer1(j,CsCard);
                    if (z == 'c')
                    {
                        NumRaise++;
                    }
                    else
                    {
                        x = 'c';
                        NumRaise++;
                        break;
                    }
                    cout << "You can choose whether you want to Raise or not." << endl;
                    cout << "Press 'c' to further Raise 10 HKD and 's' not to Raise" << endl;
                    cin >> x;
                    if (x == 'c')
                    {
                        Fund = Fund - 10;
                        cout << "Currently you have fund " << Fund << " HKD" << endl;
                        NumRaise++;
                    }
                    else
                    {
                        Fund = Fund + 10;
                        break;
                    }
                }
                changeFund = Result(j, NumRaise, x, PlayerCard, CsCard, computer);// Calculate the money changed in this round and record it.
            }
            NumRound++;
            computer.clear();
            Fund = Fund + changeFund;
            ofstream fout;
            fout.open("Result_token.txt");
            if ( fout.fail() )
            {
                cout << "Error in file opening!"  << endl;
                exit(1);
            }
            fout << Fund << endl;
            fout.close();
            if (Fund > 10)
            { // To check if the player can continue to play the game.
                cout << "Now you have fund: " << Fund << " HKD" << endl; // Make the output and tell player their latest fund
                cout << "Please press 'Y' to continue the next round or 'N' to exit the game: " << endl;
                cin >> y;
            }
            else
            {
                cout << "Now you have fund: " << Fund << " HKD" << endl;
                cout << "You don't have enough fund to play!" << endl;
                cout << "You lose!" << endl;
                break; // If the player do not have enough fund to play, the game will be forced to end
            }
        }
        cout << "The game is end. Bye Bye :)" << endl;
        break;
    }
    return 0;
}
