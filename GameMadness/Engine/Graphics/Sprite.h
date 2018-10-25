#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW\glfw3.h"
#include "Texture.h"
#include <iostream>
#include <string>
using namespace std;

class Sprite {

public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xPos, float _yPos);
	
	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(float x, float y);
	void MoveBy(float x, float y);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	
	void RotateTo(float x); //set rotation absolutely 
	void RotateBy(float x); //set rotation relatively (basically add x to it)

	void SetScale(float x);
	void SetScale(float x, float y);

private:
	Texture texture;

	float speed;

	float xPos;
	float yPos;
	float rot; //rotation
	float xScale;
	float yScale;

};

#endif
