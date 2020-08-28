#include "Init.h"

#pragma region Constructor

Init::Init() {
	ifstream inFile;
	inFile.open("map.txt");
	int count = 0;
	string value;
	while (!inFile.eof()) {
		getline(inFile, value);
		this->enumMap.insert(pair<string, int>(value, count));
		count++;
	}
	inFile.close();
	this->enumChat.insert(pair<string, int>("Bich", 0));
	this->enumChat.insert(pair<string, int>("Chuon", 1));
	this->enumChat.insert(pair<string, int>("Ro", 2));
	this->enumChat.insert(pair<string, int>("Co", 3));
}

Init::~Init() {

}
#pragma endregion


#pragma region LayGiaTri

map<string, int> Init::getEnumMap() {
	return this->enumMap;
}

map<string, int> Init:: getEnumChat() {
	return this->enumChat;
}

void Init::operator=(map<string,int> enumMap){
	this->enumMap = enumMap;
}

#pragma endregion

