#include "App.h"

App::App() {
	player = new Player();
	deck = new Deck();
	deck->tronBoBai();
	player->pushHand(deck->getBoBai());
	player->sortHand();
}

App::~App() {
	delete player;
	delete deck;
}

void App::Init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1600, 800, 0);
	glEnable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void App::display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.89, 0.055, 0.055);
	glBegin(GL_POLYGON);
	glVertex2f(500, 150);
	glVertex2f(1100, 150);
	glVertex2f(1150, 500);
	glVertex2f(450, 500);
	glEnd();

	glColor3f(0.055, 0.89, 0.055);
	glBegin(GL_POLYGON);
	glVertex2f(510, 160);
	glVertex2f(1090, 160);
	glVertex2f(1140, 490);
	glVertex2f(460, 490);
	glEnd();

	glColor3f(0.055, 0.89, 1);
	glBegin(GL_POLYGON);
	glVertex2f(1000, 700);
	glVertex2f(1100, 700);
	glVertex2f(1100, 750);
	glVertex2f(1000, 750);
	glEnd();

	player->showCard();

}

void App::showTable() {
	for (int i = 0;i < this->table.size();i++) {
		glColor3f(1, 1, 1);
		GLuint texture = LoadTextureAUTO(this->table.at(i).getImage());
		glBindTexture(GL_TEXTURE_2D, texture);
		//glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(1, 0);
		glVertex2f(560 + i * 50, 280);
		glTexCoord2f(0, 0);
		glVertex2f(640 + i * 50, 280);
		glTexCoord2f(0, 1);
		glVertex2f(645 + i * 50, 390);
		glTexCoord2f(1, 1);
		glVertex2f(555 + i * 50, 390);
		glEnd();
		//glPopMatrix();
	}
}

void App::clickMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//glutSwapBuffers();
		if (x >= 75 && x <= 170 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 1) {
				player->pushCheck(player->getHand()[0]);
				return;
			}

		if (x >= 185 && x <= 280 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 2) {
				player->pushCheck(player->getHand()[1]);

				return;
			}
		if (x >= 295 && x <= 390 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 3) {
				player->pushCheck(player->getHand()[2]);
				return;
			}
		if (x >= 405 && x <= 500 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 4) {
				player->pushCheck(player->getHand()[3]);
				return;
			}
		if (x >= 515 && x <= 610 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 5) {
				player->pushCheck(player->getHand()[4]);
				return;
			}
		if (x >= 625 && x <= 720 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 6) {
				player->pushCheck(player->getHand()[5]);
				return;
			}
		if (x >= 735 && x <= 830 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 7) {
				player->pushCheck(player->getHand()[6]);
				return;
			}
		if (x >= 845 && x <= 940 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 8) {
				player->pushCheck(player->getHand()[7]);
				return;
			}
		if (x >= 955 && x <= 1050 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 9) {
				player->pushCheck(player->getHand()[8]);
				return;
			}
		if (x >= 1065 && x <= 1160 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 10) {
				player->pushCheck(player->getHand()[9]);
				return;
			}
		if (x >= 1175 && x <= 1270 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 11) {
				player->pushCheck(player->getHand()[10]);
				return;
			}
		if (x >= 1285 && x <= 1380 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 12) {
				player->pushCheck(player->getHand()[11]);
				return;
			}
		if (x >= 1395 && x <= 1490 && y >= 500 && y <= 670)
			if (player->getHand().size() >= 13) {
				player->pushCheck(player->getHand()[12]);

				return;
			}
		if (x >= 950 && x <= 1050 && y >= 700 && y <= 750) {

			if(this->player->getCheck().size() > 0)
			this->player->sortCheck();

			if (player->isValid() == true) {
				for (int i = this->table.size() - 1;i >= 0;i--) {
					this->table.erase(this->table.begin() + i);
				}
				for (int i = 0;i < player->getCheck().size();i++) {
					this->table.push_back(this->player->getCheck()[i]);
				}
				for (int i = 0;i < this->table.size(); i++) {
					player->removeHand(this->table[i]);
				}
				player->removeAllCheck();
			}
		}
	}
}