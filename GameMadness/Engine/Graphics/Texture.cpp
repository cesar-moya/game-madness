#include "Texture.h"

Texture::Texture() {
	id = -1; //this is what openGL tracks the texture as
}

Texture::Texture(int _id) {
	id = _id;
	if (!GetTextureParams()) {
		cout << "Error loading image with id: " << id << endl;
	}
}

Texture::Texture(string path) {
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);
	if (!GetTextureParams()) {
		cout << "Error loading image: " << path << endl;
	}
	cout << "Texture Width: " << width << endl;
	cout << "Texture Height: " << height << endl;

}

int Texture::GetId() {
	return id;
}

int Texture::GetWidth() {
	return width;
}

int Texture::GetHeight() {
	return height;
}

bool Texture::GetTextureParams() {
	if (id > 0) {
		int mipLevel = 0; //the higher the number ... has to  do with compression?
		//bind the texture to GL_TEXTURE_2D
		glBindTexture(GL_TEXTURE_2D, id);
		//we pull the parameter "GL_TEXTURE_WIDTH" and store it on width variable, same for height
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height);
		return true;
	}
	return false;
}