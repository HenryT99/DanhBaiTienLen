#include "Deck.h"

#pragma region Constructor
Deck::Deck() {
	
	Init init = Init();
	ifstream inFile;
	inFile.open("Deck.txt");
	string temp;
	int count = 0;
	while (!inFile.eof()) {
		string path = "images/";
		getline(inFile, temp);
		for (int i = 0;i < temp.length();i++) {
			if (temp.at(i) == '-') {
				//cout << temp.substr(i + 1, temp.length() - 1) << endl;
				BoBai[count] = LaBai(temp.substr(0, i),
					temp.substr(i + 1, temp.length()),
					init.getEnumMap(),
					init.getEnumChat(), path.append(temp).append(".png"));
				break;
			}
		}
		count++;
	}
	inFile.close();
}

Deck::~Deck() {

}
#pragma endregion

#pragma region CacHamXuLy

void Deck::xemBoBai() {
	for (int i = 0;i < 52;i++)
	{
		cout << BoBai[i].getGiaTri() << "\t" << BoBai[i].getTenChat() << "\t" << endl;
	}
}

void swap(LaBai& a, LaBai& b) {
	LaBai temp = a;
	a = b;
	b = temp;
}

void Deck::tronBoBai() {///Tron Bo Bai
	std::random_device rd;
	std::mt19937_64 rng(rd());
	for (int i = 0;i < 52;i++) {
		std::uniform_int_distribution<int> x(0,51);
		swap(BoBai[i], BoBai[x(rng)]);
	}
}

LaBai* Deck::getBoBai() {
	return this->BoBai;
}
#pragma endregion


