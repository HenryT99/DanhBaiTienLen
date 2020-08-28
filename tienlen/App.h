#pragma once
#include"General.h"
#include"Player.h"
#include"Deck.h"
class App
{
private:
	Player* player;
	Deck* deck;
	vector<LaBai> table;
public:
	App();
	~App();

	void Init();
	void Main(int, char**);
	void display();
	void showTable();
	void clickMouse(int, int, int, int);
};

