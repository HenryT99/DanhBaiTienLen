#include "Player.h"

#pragma region Hand

void Player::pushHand(LaBai lb[]) {
	for (int i = 0;i < 13;i++) {
		this->hand.push_back(lb[i]);
	}
}

void Player::showCard() {
	glColor3f(1, 1, 1);
	for (int i = 0;i < this->hand.size();i++) {
		for (int j = 0;j < this->check.size();j++) {
			if (this->check[j] == this->hand[i]) {
				glColor3f(1, 1, 0);
				glBegin(GL_POLYGON);
				glVertex2f(70 + i * 110, 545);
				glVertex2f(175 + i * 110, 545);
				glVertex2f(175 + i * 110, 675);
				glVertex2f(70 + i * 110, 675);
				glEnd();
			}
		}
		glColor3f(1, 1, 1);
		GLuint texture = LoadTextureAUTO(this->hand.at(i).getImage());
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(1, 0);
		glVertex2f(75 + i * 110, 550);
		glTexCoord2f(0, 0);
		glVertex2f(170 + i * 110, 550);
		glTexCoord2f(0, 1);
		glVertex2f(170 + i * 110, 670);
		glTexCoord2f(1, 1);
		glVertex2f(75 + i * 110, 670);
		glEnd();
		glPopMatrix();
	}
}

void Player::sortHand() {

	for (int i = 0;i < this->hand.size() - 1;i++) {
		for (int j = 0;j < this->hand.size() - 1 - i;j++) {
			if (this->hand[j].getGiaTri() > this->hand[j + 1].getGiaTri()) {
				swap(this->hand[j], this->hand[j + 1]);
			}
		}
	}
}

void Player::pushCheck(LaBai lb) {
	for (int i = 0;i < this->check.size();i++) {// kiểm tra lá bài có trong bộ check
		if (this->check[i] == lb) {
			this->check.erase(this->check.begin() + i);
			return;
		}
	}
	this->check.push_back(lb);
}

vector<LaBai> Player::getHand() {
	return this->hand;
}

void Player::removeHand(LaBai lb) {
	for (int i = 0;i < this->hand.size();i++) {
		if (this->hand[i] == lb){
			this->hand.erase(this->hand.begin() + i);
			break;
		}	
	}
}

vector<LaBai> Player::getCheck() {
	return this->check;
}

void Player::sortCheck() {
	for (int i = 0;i < this->check.size() - 1;i++) {
		for (int j = 0;j < this->check.size() - 1 - i;j++) {
			if (this->check[j ] > this->check[j + 1]) {
				swap(this->check[j], this->check[j + 1]);
			}
		}
	}
}

void Player::removeAllCheck() {
	for (int i = this->check.size() - 1;i >=0 ;i--) {
		this->check.erase(this->check.begin() + i);
	}
}

bool Player::isDouble() {//Kiểm tra đôi
	if (this->check.size() == 2) {//2 lá
		if (this->check[0].getGiaTri() == this->check[1].getGiaTri()) {
			return true;
		}
		else return false;
	}
	else return false;
}

bool Player::isDouble(LaBai lb1, LaBai lb2) {//Dùng kiểm tra 3-4-5-6 đôi thông
	if (lb1.getGiaTri() == lb2.getGiaTri()) {
		return true;
	}
		
	else return false;
}
//
bool Player::isTripple() {//Kiểm tra ba lá
	if (this->check.size() == 3) {
		if (this->check[0].getGiaTri() == this->check[1].getGiaTri() && this->check[0].getGiaTri() == this->check[2].getGiaTri())//3 Lá giống nhau
			return true;
		else return false;
	}
	//return false;
}
//
//bool Player::isQuad() {//Kiểm tra Tứ quý
//	bool state = true;
//	if (this->check.size() == 4)//Tứ quý có 4 lá
//		for (int i = 0;i < this->check.size() - 1;i++) {
//			if (this->check[i].getGiaTri() != this->check[i + 1].getGiaTri()) {
//				state = false;
//				break;
//			}
//
//		}
//	else state = false;
//	return state;
//}
//
//bool Player::isLobby() {//Kiểm tra sảnh
//	bool state = true;
//	if (this->check.size() > 2) {//Sảnh có 3 lá trở lên
//		for (int i = 0;i < this->check.size() - 1;i++) {
//			if (this->check[i].getGiaTri() == this->check[i + 1].getGiaTri() ||
//				this->check[i].getGiaTri() <= this->check[i + 1].getGiaTri() - 2 ||
//				this->check[i].getGiaTri() == 12) {//giả sử Check được sắp xếp từ bé đến lớn, kiểm tra nếu có một lá bất kì giống hoặc chênh nhau từ 2 giá trị trở lên hoặc có con heo thì false
//				state = false;
//				break;
//			}
//
//		}
//	}
//	return state;
//}
//
//bool Player::isLobby(LaBai lb[], int n) {//Kiem tra sanh doi
//	bool state = true;
//	for (int i = 0;i < n - 1;i++) {
//		if (lb[i].getGiaTri() == lb[i + 1].getGiaTri() ||
//			lb[i].getGiaTri() <= lb[i + 1].getGiaTri() - 2 ||
//			lb[i].getGiaTri() == 2)
//			state = false;
//	}
//	return state;
//}
//
//bool Player::isThreePair() {
//	if (this->check.size() == 6) {
//		if (isDouble(this->check[0], this->check[1]) &&
//			isDouble(this->check[2], this->check[3]) &&
//			isDouble(this->check[4], this->check[5])) {
//			LaBai lb[3] = {
//				this->check[0],
//				this->check[2],
//				this->check[4]
//			};
//			if (isLobby(lb, 3))
//				return true;
//		}
//	}
//	return false;
//}
//
//bool Player::isFourPair() {
//	if (this->check.size() == 8) {
//		if (isDouble(this->check[0], this->check[1]) &&
//			isDouble(this->check[2], this->check[3]) &&
//			isDouble(this->check[4], this->check[5]) &&
//			isDouble(this->check[6], this->check[7])) {
//			LaBai lb[4] = {
//				this->check[0],
//				this->check[2],
//				this->check[4],
//				this->check[6]
//			};
//			if (isLobby(lb, 4))
//				return true;
//		}
//	}
//	return false;
//}
//
//bool Player::isFivePair() {
//	if (this->check.size() == 10) {
//		if (isDouble(this->check[0], this->check[1]) &&
//			isDouble(this->check[2], this->check[3]) &&
//			isDouble(this->check[4], this->check[5]) &&
//			isDouble(this->check[6], this->check[7]) &&
//			isDouble(this->check[8], this->check[9])) {
//			LaBai lb[5] = {
//				this->check[0],
//				this->check[2],
//				this->check[4],
//				this->check[6],
//				this->check[8]
//			};
//			if (isLobby(lb, 5))
//				return true;
//		}
//	}
//	return false;
//}
//
//bool Player::isQuadTwo() {//Tứ quý Heo
//	if (this->isQuad() && this->check[0].getGiaTri() == 12)
//		return true;
//
//	return false;
//}

bool Player::isValid() {
	if (this->check.size() == 1)
		return true;
	else if (isDouble()||
		isTripple()
		/*isQuad()||
		isLobby()||
		isThreePair()||
		isFourPair()||
		isFivePair()*/) {
		return true;
	}
	else 
	return false;
}

#pragma endregion

