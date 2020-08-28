#pragma once
#include<stdlib.h>
#include<GL/glut.h>
#include<FreeImage.h>
#include <string>
using namespace std;
GLuint LoadTextureAUTO(string filename);
GLuint loadTexture(FIBITMAP*);
FIBITMAP* loadImage(const char* );