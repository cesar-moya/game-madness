#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include <iostream>
using namespace std;

int main() {
	cout << "Welcome to Game Madness!" << endl;
	
	Engine engine;
	const char* title = "Welcome";
	engine.Initialize(title);

	//opengameart.org to find free sprites, music etc.
	Sprite testSprite = Sprite("Assets/Art/biplane.png", 0, 0); 
	testSprite.SetScale(0.25);
	//Sprite testSprite = Sprite("Assets/Art/plane.png", 0, 0); 
	//Sprite raider = Sprite("Assets/Art/nightraider.png", 50, 50);
	
	while (true) {
		engine.Update(); //makes sure we can poll those events so we can move the screen around
		testSprite.Update();
		
		//handling input, this moves the sprite along with the mouse movement
		//testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY()); 

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
			testSprite.RotateBy(100);
		}
		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
			testSprite.RotateBy(-100);
		}
		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE)) {
			testSprite.RotateBy(100);
		}

		if (Keyboard::Key(GLFW_KEY_W)) {
			testSprite.MoveUp();
		}
		if (Keyboard::Key(GLFW_KEY_S)) {
			testSprite.MoveDown();
		}
		if (Keyboard::Key(GLFW_KEY_A)) {
			testSprite.MoveLeft();
		}
		if (Keyboard::Key(GLFW_KEY_D)) {
			testSprite.MoveRight();
		}
		
		
		//make sure to clear that back buffer, draw clear color and swap it
		engine.BeginRender(); 
		testSprite.Render();
		engine.EndRender();
	}
	
	return 0;
}

/*
SOIL: Simple Open ... to setup open gl textures (sprites)

*/