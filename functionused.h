#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#define S   "\xE2\x99\xA0" // For printing out the suit of the card
#define C   "\xE2\x99\xA3"
#define H   "\xE2\x99\xA5"
#define D   "\xE2\x99\xA6"
using namespace std;

extern string Suit[];
extern string Num[];

struct CardResult
{
    int a;
    int b;
    int c;
    int d;
}; // Create a struct to collect the points of cards

void Send_Card(vector<string>& computer, CardResult& result);

int Result(int i, int NumRaise, char a, int PlayerCard[], int CsCard[], vector<string>& computer);

char computer1(int& rounds, int CsCard[]);

#endif // FUNCTION_H_INCLUDED
