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
	vel.y += gravity;
	*pos = *pos + (vel * Engine::GetDT());
	
	//vel = Vector3(0);
}

void Rigidbody::Render(Vector3 c) {
	glLoadIdentity();
	
	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{
		//lines go vertex to vertex, different from textures, write them in 2's
		//bottom left to bottom right
		glVertex2i(-(int)size->x / 2, -(int)size->y / 2);
		glVertex2i( (int)size->x / 2, -(int)size->y / 2);

		//bottom right to top right
		glVertex2i((int)size->x / 2, -(int)size->y / 2);
		glVertex2i((int)size->x / 2,  (int)size->y / 2);

		//top right to top left
		glVertex2i((int)size->x / 2, (int)size->y / 2);
		glVertex2i(-(int)size->x / 2, (int)size->y / 2);

		//top left to bottom left
		glVertex2i(-(int)size->x / 2, (int)size->y / 2);
		glVertex2i(-(int)size->x / 2, -(int)size->y / 2);

						////bottom left to bottom right
						//glVertex2i(0, 0);
						//glVertex2i((int) size->x, 0);

						////bottom right to top right
						//glVertex2i((int) size->x, 0);
						//glVertex2i((int) size->x, (int) size->y);

						////top right to top left
						//glVertex2i((int) size->x, (int) size->y);
						//glVertex2i(0, (int) size->y);

						////top left to bottom left
						//glVertex2i(0, (int) size->y);
						//glVertex2i(0, 0);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 force) {
	vel = vel + force;
}

void Rigidbody::SetVel(Vector3 _vel) {
	vel = _vel;
	//cout << "velocity added" << endl;
}

Vector3 Rigidbody::GetVel() {
	return vel;
}

