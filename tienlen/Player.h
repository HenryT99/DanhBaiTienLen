
#include<math.h>
#include<string>
#include<iostream>
#include"LaBai.h"
#include<vector>
#include"General.h"
#pragma once
class Player
{
private:
	vector<LaBai> hand;
	vector<LaBai> check;
	int state;
	int rank;
public:
	void pushHand(LaBai[]);
	void showCard();
	void sortHand();

	void pushCheck(LaBai);
	void sortCheck();

	vector<LaBai> getHand();
	vector<LaBai> getCheck();
	void removeHand(LaBai);

	void removeAllCheck();

	bool isValid();
	bool isDouble();
	bool isDouble(LaBai, LaBai);
	bool isTripple();
	bool isQuad();
	bool isQuadTwo();
	bool isLobby();
	bool isLobby(LaBai[], int);

	bool isThreePair();
	bool isFourPair();
	bool isFivePair();
};

