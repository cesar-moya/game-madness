#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW\glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>

using namespace std;

class Sprite {

public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 v);
	
	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	
	void RotateTo(float x); //set rotation absolutely 
	void RotateBy(float x); //set rotation relatively (basically add x to it)

	void SetScale(float x);
	void SetScale(Vector3 v);

	void FlipHorizontal();
	void FlipVertical();

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;

	float speed;

	Vector3 pos;
	float rot; //rotation
	Vector3 scale;
	Vector3 size;
	Vector3 size2;
};

#endif
