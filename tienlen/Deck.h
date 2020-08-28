#pragma once
#include"Init.h"
#include "LaBai.h"
#include <random>
class Deck
{
private:
	LaBai BoBai[52];
public:
	Deck();
	~Deck();

	void xemBoBai();
	void tronBoBai();

	LaBai* getBoBai();
};

