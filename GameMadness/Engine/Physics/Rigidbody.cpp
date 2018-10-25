#include "Rigidbody.h"
#include "../Engine.h"

Rigidbody::Rigidbody() {
	friction = 1; //1 to not lose any velocity
	gravity = 0;
}

///pointers because they will be able to modify the values of the sprite passed in.
void Rigidbody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size) {
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void Rigidbody::Update() {
	//at the end of every frame we want to modify the position
	vel.x *= friction;
	vel.y -= gravity;

	*pos = *pos + (vel * Engine::GetDT());
}

void Rigidbody::Render(Vector3 c) {
	glLoadIdentity();
	
	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);
	//glScalef(scale->x, scale->y, 0);

	glColor4f(c.x, c.y, c.z, 1);
	glLineWidth(2.5);
	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i((int)size->x, 0);

		glVertex2i((int)size->x, 0);
		glVertex2i((int)size->x, (int)size->y);

		glVertex2i((int)size->x, (int)size->y);
		glVertex2i(0, (int)size->y);

		glVertex2i(0, (int)size->y);
		glVertex2i(0, 0);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 force) {
	vel = vel + force;
}

