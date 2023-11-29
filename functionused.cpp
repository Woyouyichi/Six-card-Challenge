#include <iostream>
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

extern int card1, card2, card3, card4;

void Send_Card(vector<string>& computer, CardResult& result) // Build a function to distribute cards to the player and the computer
{
    srand(time(NULL));
    card1 = rand() % 52;
    card2 = rand() % 52;
    card3 = rand() % 52;
    card4 = rand() % 52;
    computer.push_back(Suit[card3 / 13] + Num[card3 % 13]);
    computer.push_back(Suit[card4 / 13] + Num[card4 % 13]); // Remember the cards of the computer
    cout << "Your Card: " << Suit[card1/13] << Num[card1%13] << ", " << Suit[card2/13] << Num[card2%13] << endl;//Show the cards of the player
    int Num1[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    int a=Num1[card1%13], b=Num1[card2%13], c=Num1[card3%13], d=Num1[card4%13];
    result.a = a;
    result.b = b;
    result.c = c;
    result.d = d; // get the cards' points
}

int Result(int i, int NumRaise, char a, int PlayerCard[], int CsCard[], vector<string>& computer) // Build a function to show the final result of each round
{
    int token, playerSum=0, csSum=0;
    if (i==0)
    {
        token = 10 * (NumRaise + 1);
        if (a == 'c')
        {
            cout << "The computer's cards are following:" << endl;
            for (const auto& card : computer)
            {
                cout << card << " ";
            }

            cout << endl;
            cout << "You win " << token << " HKD " << "in this round game." << endl;
        }
        else
        {
            cout << "You decided to quit the game." << endl;
            cout << "The computer's cards are following:" << endl;
            for (const auto& card : computer)
            {
                cout << card << " ";
            }
            cout << endl;
            cout << "You lose " << token << " HKD " << "in this round game." << endl;
            token = 0;
        }

    }
    else if (i==1)
    {
        token = 10 * (NumRaise + 1);
        if (a == 'c')
        {
            cout << "The computer's cards are following:" << endl;
            for (const auto& card : computer)
            {
                cout << card << " ";
            }
            cout << endl;
            cout << "You win " << token << " HKD " << "in this round game." << endl;
        }
        else
        {
            cout << "You decided to quit the game." << endl;
            cout << "The computer's cards are following:" << endl;
            for (const auto& card : computer)
            {
                cout << card << " ";
            }
            cout << endl;
            cout << "You lose " << token << " HKD " << "in this round game." << endl;
            token = 0;
        }

    }
    else
    {
        for (int l=0; l<6;l++)
            playerSum = playerSum + PlayerCard[l];
        for (int m=0; m<6;m++)
            csSum = csSum + CsCard[m];
        token = 10 * (NumRaise + 1);
        if (playerSum > csSum)
        {
            cout << "The computer's cards are following:" << endl;
            for (const auto& card : computer)
            {
                cout << card << " ";
            }
            cout << endl;
            cout << "You win " << token << " HKD " << "in this round game." << endl;
        }
        else
        {
            cout << "The computer's cards are following:" << endl;
            for (const auto& card : computer)
            {
                cout << card << " ";
            }
            cout << endl;
            cout << "You lose " << token << " HKD " << "in this round game." << endl;
            token = 0;
        }
    }
    return token;
}



char computer1(int& rounds, int CsCard[]) // Build a function to determine the decision made by the computer according to the known cards.
{
    int Cpoints = 0;
    if (rounds == 0)
    {
        for (int v=0;v< (rounds+1)*2; v++)
            Cpoints = Cpoints + CsCard[v];
        if (Cpoints < 14)
        {
            cout << "The computer decided to quit the game." << endl;
            return 's';
        }
        else
        {
            cout << "The computer decided to raise." << endl;
            return 'c';
        }
    }
    else if (rounds == 1)
    {
        for (int v=0;v< (rounds+1)*2; v++)
            Cpoints = Cpoints + CsCard[v];
        if (Cpoints < 32)
        {
            cout << "The computer decided to quit the game." << endl;
            return 's';
        }
        else
        {
            cout << "The computer decided to raise." << endl;
            return 'c';
        }
    }
    else
    {
        for (int v=0;v< (rounds+1)*2; v++)
            Cpoints = Cpoints + CsCard[v];
        if (Cpoints < 48)
        {
            cout << "The computer decided to quit the game." << endl;
            return 's';
        }
        else
        {
            cout << "The computer decided to raise." << endl;
            return 'c';
        }
    }
}


