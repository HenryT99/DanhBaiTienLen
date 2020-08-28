#include "Chat.h"

map<string, int> mapChat;
//Các hàm khởi tạo và hủy
#pragma region Constructor
Chat::Chat(int tenChat) {
	this->TenChat = tenChat;
}

Chat::Chat(){}

Chat::~Chat() {

}
#pragma endregion


//Các hàm xử lý so sánh
#pragma region SoSanh

#pragma endregion

//Các hàm xủ lý gán
#pragma region GetterSetter

void Chat::operator=(const Chat chat1){
	this->TenChat = chat1.TenChat;
}

int Chat::getTenChat() {
	return this->TenChat;
}

#pragma endregion
