#ifndef GAME_FLAPPER
#define GAME_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"
#include "../Engine/Math/Rect.h"

class Flapper{

public:
	Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();
	void Flap();

	Sprite& GetSprite();
	Rigidbody& GetRB();

	void Reset();

private:
	Sprite sprite;
	Rigidbody rb;

	float flapForce;
	float maxRot;
	float minRot;
};

#endif

