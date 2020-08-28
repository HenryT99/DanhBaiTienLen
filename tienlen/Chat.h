#pragma once
#include<string>
#include<map>
using namespace std;
class Chat
{
protected:
	int TenChat;
public:
	Chat(int);
	Chat();
	~Chat();
	void operator = (const Chat);
	int getTenChat();
};

