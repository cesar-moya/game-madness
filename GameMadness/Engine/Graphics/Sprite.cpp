#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite() {
	xPos = 0;
	yPos = 0;
	texture = Texture();
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath) {
	texture = Texture(imagePath);
	xPos = 0;
	yPos = 0;
	rot - 0;
	speed = 100;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) {
	texture = Texture(imagePath);
	xPos = _xPos;
	yPos = _yPos;
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
	glTranslatef(xPos, yPos, 0);
	//ROTATE
	glRotatef(rot, 0, 0, 1); //rotate on the z axis by rot "degrees" or whatever
	//SCALE
	glScalef(xScale, yScale, 1); //scale on x and y, but not on Z. 1 = 100% 

	//RENDERING
	//first we setup a color, the sprite obviously has a color, but this also sets it up to change it or background etc
	glColor4f(1, 1, 1, 1); //white
	glBegin(GL_QUADS); //begins rendering, the render mode is QUADS b/c it's 2D
	{
		//they usually put these lines side by side b/c they deal with the same data
		//the values xPos and yPos here are "from" where you translated before (glTranslatef)
		//bottom left
		glTexCoord2f(0, 0);    glVertex2f(0, 0);
		//bottom right
		glTexCoord2f(1, 0);    glVertex2f(texture.GetWidth(), 0);
		//top right
		glTexCoord2f(1, 1);    glVertex2f(texture.GetWidth(), texture.GetHeight());
		//top left
		glTexCoord2f(0, 1);    glVertex2f(0, texture.GetHeight());
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

void Sprite::MoveTo(float x, float y) {
	xPos = x;
	yPos = y;
}

void Sprite::MoveBy(float x, float y){
	xPos += x * Engine::GetDT();
	yPos += y * Engine::GetDT();
}

void Sprite::MoveLeft(){
	xPos -= speed * Engine::GetDT();  //speed might change based on how long the last frame took
}

void Sprite::MoveRight(){
	xPos += speed * Engine::GetDT();
}

void Sprite::MoveUp(){
	yPos += speed * Engine::GetDT();
}

void Sprite::MoveDown(){
	yPos -= speed * Engine::GetDT();
}

///Scales proportionally
void Sprite::RotateTo(float x) {
	rot = x;
}

void Sprite::RotateBy(float x) {
	rot += x * Engine::GetDT();
}

///scales not proportionally
void Sprite::SetScale(float x, float y) {
	xScale = x;
	yScale = y;
}

void Sprite::SetScale(float x) {
	xScale = x;
	yScale = x; //why?
}

