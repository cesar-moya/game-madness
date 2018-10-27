#ifndef GAME_RIGIDBODY
#define GAME_RIGIDBODY

#include "../Math/Vector3.h"

///This would work with the sprite, rigibody should be a part of the sprite
class Rigidbody {

public:
	Rigidbody();
	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size);
				  //float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size
	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);


private:
	Vector3* pos;
	float* rot;
	Vector3* scale;
	Vector3* size;

	//how much is this object affected by gravity
	float gravity; 
	//drag as you're moving
	float friction;
	Vector3 vel; //velocity, affected by gravity and friction

};

#endif
