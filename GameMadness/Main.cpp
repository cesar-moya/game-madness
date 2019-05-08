#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Flappy/Flapper.h"
#include "Flappy/InputManager.h"
#include "Flappy/Pipe.h"

#include <iostream>
using namespace std;

int main() {
	cout << "Welcome to Game Madness!" << endl;
	
	Engine engine;
	const char* title = "Welcome";
	engine.Initialize(title);

	//opengameart.org to find free sprites, music etc.
	Sprite testSprite = Sprite("Assets/Art/biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0)); 
	testSprite.SetScale(0.15f);

	//Sprite testSprite = Sprite("Assets/Art/plane.png", 0, 0); 
	//Sprite raider = Sprite("Assets/Art/nightraider.png", 50, 50);

	Flapper player(testSprite);

	Pipe::Initialize();
	Pipe pipe = Pipe(Vector3(0, 0, 0));

	InputManager im(&player, &pipe);
	
	while (true) {
		engine.Update(); //makes sure we can poll those events so we can move the screen around
		player.Update();
		pipe.Update();
		
		bool isColliding = Rigidbody::IsColliding(player.GetRB(), pipe.GetTopRB()) || Rigidbody::IsColliding(player.GetRB(), pipe.GetBotRB());
		cout << (isColliding ? "COLLIDING!!" : "....") << endl;

		//handling input, this moves the sprite along with the mouse movement
		//testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY()); 
		im.Update();
		
		
		//make sure to clear that back buffer, draw clear color and swap it
		engine.BeginRender(); 
		player.Render();
		pipe.Render();
		engine.EndRender();
	}
	
	return 0;
}

/*
SOIL: Simple Open ... to setup open gl textures (sprites)

*/