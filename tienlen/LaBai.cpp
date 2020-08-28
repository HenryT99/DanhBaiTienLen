#include "LaBai.h"


#pragma region Constructor

LaBai :: LaBai(string GiaTri, string chat, map<string, int> enumMap,map<string, int> enumChat, string image):Chat(enumChat[chat]) {
	this->GiaTri = enumMap[GiaTri];
	this->Image = image;
}

LaBai::LaBai() {

}

LaBai::~LaBai(){}

#pragma endregion

#pragma region SoSanh

bool LaBai::operator>(LaBai labai) {
	if (this->GiaTri > labai.GiaTri)
		return true;
	else if (this->GiaTri == labai.GiaTri) {
		if (this->TenChat > labai.TenChat)
			return true;
		else
			return false;
	}
	else if (this->GiaTri < labai.GiaTri)
		return false;
		
}

bool LaBai::operator==(LaBai labai) {
	if (this->GiaTri == labai.GiaTri && this->getTenChat() == labai.getTenChat())
		return true;
	return false;
}

void LaBai:: operator=(LaBai labai) {
	this->GiaTri = labai.GiaTri;
	this->TenChat = labai.TenChat;
	this->Image = labai.Image;
}

#pragma endregion

#pragma region GetterSetter

int LaBai::getGiaTri() {
	return this->GiaTri;
}

string LaBai::getImage() {
	return this->Image;
}

#pragma endregion
