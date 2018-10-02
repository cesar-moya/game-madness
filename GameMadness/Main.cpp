#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"

#include <iostream>
using namespace std;

int main() {
	cout << "hello world" << endl;
	
	Engine engine;
	const char* title = "Welcome";
	engine.Initialize(title);

	//opengameart.org to find free sprites, music etc.
	Sprite biplane = Sprite("Assets/Art/biplane.png", 0, 200); 
	//Sprite testSprite = Sprite("Assets/Art/plane.png", 0, 0); 
	Sprite raider = Sprite("Assets/Art/nightraider.png", 50, 50);
	
	
	while (true) {
		engine.Update(); //makes sure we can poll those events so we can move the screen around
		biplane.Update();
		raider.Update();
		
		//make sure to clear that back buffer, draw clear color and swap it
		engine.BeginRender(); 

		raider.Render();
		biplane.Render();
		
		engine.EndRender();
	}
	
	return 0;
}

/*
SOIL: Simple Open ... to setup open gl textures (sprites)

*/