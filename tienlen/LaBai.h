#pragma once
#include"Chat.h"
#include <map>

class LaBai : public Chat
{
private:
	int GiaTri;
	string Image;
public:
	LaBai();
	LaBai(string,string, map<string, int>, map<string,int>, string image);
	~LaBai();
	
	bool operator>(LaBai);
	bool operator==(LaBai);
	void operator=(LaBai);

	int getGiaTri();
	string getImage();
};

