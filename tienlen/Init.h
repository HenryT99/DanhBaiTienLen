#pragma once
#include<map>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Init
{

private:
	map<string, int> enumMap;
	map<string, int> enumChat;
public:
	Init();
	~Init();
	map<string, int> getEnumMap();
	void operator=(map<string, int>);
	map<string, int> getEnumChat();
};

