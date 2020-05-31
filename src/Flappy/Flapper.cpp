#include "Flapper.h"
#include "../Engine/Engine.h"

Flapper::Flapper() {
	flapForce = 750;
	maxRot = 30;
	minRot = -maxRot;
}

Flapper::Flapper(Sprite _sprite) : Flapper() {
	sprite = _sprite;
	Rect boundingRect = Rect();
	Vector3 sizeOffset(0.8, 0.3, 1);
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale() * sizeOffset);
	rb.Initialize(0.8f, -40, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
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
	sprite.RotateTo(newRot);
}

void Flapper::Render() {
	sprite.Render();
	rb.Render(Vector3(0,0,0));
}

void Flapper::Flap() {
	rb.SetVel(Vector3(0, flapForce, 0));
	sprite.RotateTo(maxRot);
	//sprite.RotateBy(10);
}

Sprite& Flapper::GetSprite() {
	return sprite;
}

Rigidbody& Flapper::GetRB() {
	return rb;
}

void Flapper::Reset() {
	sprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	sprite.RotateTo(0);
	rb.SetVel(Vector3(0, 0, 0));
	
}
