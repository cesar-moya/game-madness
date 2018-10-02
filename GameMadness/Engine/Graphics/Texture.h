#ifndef GAME_TEXTURE
#define GAME_TEXTURE

#include "GLFW\glfw3.h"
#include "soil.h"

#include <string>
#include <iostream>
using namespace std;

class Texture {

public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetId();
	int GetWidth();
	int GetHeight();

private:
	int id;
	int width;
	int height;

	bool GetTextureParams();

};

#endif
