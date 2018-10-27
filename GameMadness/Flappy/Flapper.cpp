#include "Flapper.h"
#include "../Engine/Engine.h"


Flapper::Flapper() {
	flapForce = 750;
	maxRot = 30;
	minRot = -maxRot;
}

Flapper::Flapper(Sprite _sprite) : Flapper() {
	sprite = _sprite;
	rb.Initialize(0.8f, -40, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());

}

void Flapper::Update() {
	sprite.Update();
	rb.Update();
	
	float yVel = rb.GetVel().y;
	if (flapForce == 0) {
		cout << "flapForce cannot be 0, division by zero prevented, world is saved!, setting to 750" << endl;
		flapForce = 750;
	}
	float newRot = (maxRot / flapForce) * yVel;
	cout << "yVel:" << yVel << ", newRot:" << newRot << endl;

	sprite.RotateTo(newRot);
}

void Flapper::Render() {
	sprite.Render();
	rb.Render(Vector3(0,0,0));
}

void Flapper::Flap() {
	//rb.AddForce(Vector3(0, 50, 0));
	rb.SetVel(Vector3(0, flapForce, 0));
	sprite.RotateTo(maxRot);
	
}

Sprite& Flapper::GetSprite() {
	return sprite;
}

Rigidbody& Flapper::GetRB() {
	return rb;
}

