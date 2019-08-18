#include "Sprite.h"
#include "../Engine.h"
#include "../Math/Vector3.h"

Sprite::Sprite() {
	pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3(0);
	speed = 5;
	texture = Texture();
}

Sprite::Sprite(string imagePath) {
	texture = Texture(imagePath);
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath, Vector3 v) {
	texture = Texture(imagePath);
	pos = v;
	scale = Vector3(1);
	size = Vector3((float) texture.GetWidth(), (float) texture.GetHeight(), 1);
	rot = 0;
	speed = 100;
}

void Sprite::Update() {
	//rot++; //enable to rotate automatically on the z axis
}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetId());
	glLoadIdentity(); //load identity matrix

	//execute translations on the matrix, need to happen in THIS order:
	//TRANSLATE -> ROTATE -> SCALE

	//TRANSLATE
	glTranslatef(pos.x, pos.y, 0);
	//ROTATE
	glRotatef(rot, 0, 0, 1); //rotate on the z axis by rot "degrees" or whatever
	//SCALE
	glScalef(scale.x, scale.y, 1); //scale on x and y, but not on Z. 1 = 100% 

	//RENDERING
	//first we setup a color, the sprite obviously has a color, but this also sets it up to change it or background etc
	glColor4f(1, 1, 1, 1); //white
	
	glBegin(GL_QUADS); //begins rendering, the render mode is QUADS b/c it's 2D
	{
		//they usually put these lines side by side b/c they deal with the same data
		//the values xPos and yPos here are "from" where you translated before (glTranslatef)
		
		glTexCoord2f(0, 0);    glVertex2i(-texture.GetWidth() / 2, -texture.GetHeight() / 2);
		//bottom right
		glTexCoord2f(1, 0);    glVertex2i(texture.GetWidth() / 2, -texture.GetHeight() / 2);
		//top right
		glTexCoord2f(1, 1);    glVertex2i(texture.GetWidth() / 2, texture.GetHeight() / 2);
		//top left
		glTexCoord2f(0, 1);    glVertex2i(-texture.GetWidth() / 2, texture.GetHeight() / 2);
		//bottom left
							//glTexCoord2f(0, 0);    glVertex2i(0, 0);
							////bottom right
							//glTexCoord2f(1, 0);    glVertex2i(texture.GetWidth(), 0);
							////top right
							//glTexCoord2f(1, 1);    glVertex2i(texture.GetWidth(), texture.GetHeight());
							////top left
							//glTexCoord2f(0, 1);    glVertex2i(0, texture.GetHeight());
	}
	glEnd(); //ends the drawing

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x){
	speed += x;
}

void Sprite::MoveTo(Vector3 v) {
	pos = v;
}

void Sprite::MoveBy(Vector3 v){
	pos = pos + (v * Engine::GetDT());
}

void Sprite::MoveLeft(){
	//xPos -= speed * Engine::GetDT();  //speed might change based on how long the last frame took
	pos = pos - Vector3(speed * Engine::GetDT(), 0, 0);
}

void Sprite::MoveRight(){
	pos = pos + Vector3(speed * Engine::GetDT(), 0, 0);
}

void Sprite::MoveUp(){
	pos = pos + Vector3(0, speed * Engine::GetDT(), 0);
}

void Sprite::MoveDown(){
	pos = pos - Vector3(0, speed * Engine::GetDT(), 0);
}

///Scales proportionally
void Sprite::RotateTo(float x) {
	rot = x;
}

void Sprite::RotateBy(float x) {
	rot += x * Engine::GetDT();
}

void Sprite::SetScale(float x) {
	scale = Vector3(x);
}

///scales not proportionally
void Sprite::SetScale(Vector3 v) {
	scale = v;
}

void Sprite::FlipHorizontal() {
	scale.x = -scale.x;
}

void Sprite::FlipVertical() {
	scale.y = -scale.y;
}

Vector3* Sprite::GetPos() {
	return &pos;
}

float* Sprite::GetRot() {
	return &rot;
}

Vector3* Sprite::GetScale() {
	return &scale;
}

Vector3* Sprite::GetSize() {
	return &size;
}

