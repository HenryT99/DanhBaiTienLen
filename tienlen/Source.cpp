#include"General.h"
#include<math.h>
#include<iostream>
#include"App.h"

App app = App();

void display() {
	app.display();
	app.showTable();
	glutSwapBuffers();
}

void specialKey(int key, int x, int y) {
	cout << key;
}

void key(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27:
		glutDestroyWindow(glutGetWindow());
		exit(0);
		break;
	default:
		break;
	}
}

void clickMouse(int button, int state, int x, int y) {
	app.clickMouse(button, state, x, y);
	//glutSwapBuffers();
	display();
}

int main(int argc, char* argv[]){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 50);
	glutInitWindowSize(1600, 800);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	app.Init();

	glutDisplayFunc(display);
	glutMouseFunc(clickMouse);
	glutSpecialFunc(specialKey);
	glutKeyboardFunc(key);

	glutMainLoop();
	return 0;
}
