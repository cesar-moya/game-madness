#ifndef GAME_RIGIDBODY
#define GAME_RIGIDBODY

#include "../Math/Vector3.h"
#include "../Math/Rect.h"

///This would work with the sprite, rigibody should be a part of the sprite
class Rigidbody {

public:

	static bool IsColliding(const Rigidbody& rbA, const Rigidbody& rbB);

	Rigidbody();
	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect);
	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);
	void SetVel(Vector3 _vel);
	Vector3 GetVel();


private:
	Vector3* pos;
	float* rot;
	float lastRot;
	Vector3* scale;
	Vector3* size;

	//how much is this object affected by gravity
	float gravity; 
	//drag as you're moving
	float friction;
	Vector3 vel; //velocity, affected by gravity and friction

	Rect boundingRect;
};

#endif
