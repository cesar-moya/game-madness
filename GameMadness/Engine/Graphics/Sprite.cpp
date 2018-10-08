#include "Sprite.h"

Sprite::Sprite() {
	xPos = 0;
	yPos = 0;
	texture = Texture();
}

Sprite::Sprite(string imagePath) {
	texture = Texture(imagePath);
	xPos = 0;
	yPos = 0;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) {
	texture = Texture(imagePath);
	xPos = _xPos;
	yPos = _yPos;
}

void Sprite::Update() {

}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetId());
	glLoadIdentity(); //load identity matrix

	//execute translations on the matrix, need to happen in THIS order:
	//TRANSLATE -> ROTATE -> SCALE

	//TRANSLATE
	glTranslatef(xPos, yPos, 0);

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

		/*glTexCoord2f(0, 0);		glVertex2i(-texture.GetWidth() / 2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 0);		glVertex2i(texture.GetWidth() / 2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 1);		glVertex2i(texture.GetWidth() / 2, texture.GetHeight() / 2);
		glTexCoord2f(0, 1);		glVertex2i(-texture.GetWidth() / 2, texture.GetHeight() / 2);*/

		/*
		glTexCoord2f(0, 0);    glVertex2f(0, 0);
		////bottom right
		glTexCoord2f(1, 0);    glVertex2f(texture.GetWidth(), 0);
		////top right
		glTexCoord2f(1, 1);    glVertex2f(texture.GetWidth(), texture.GetHeight());
		////top left
		glTexCoord2f(0, 1);    glVertex2f(0, texture.GetHeight());
		*/
	}

	glEnd(); //ends the drawing

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SetPos(float x, float y) {
	xPos = x;
	yPos = y;
}