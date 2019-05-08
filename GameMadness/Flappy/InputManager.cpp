#include "InputManager.h"

InputManager::InputManager(Flapper* _flapper, Pipe* _pipe) {
	flapper = _flapper;
	pipe = _pipe;
}

void InputManager::Update() {
	
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flapper->Flap();
	}

	pipe->MoveTo(Vector3(Mouse::GetMouseX(), Mouse::GetMouseY(), 0));

	/*if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flapper->GetSprite().RotateBy(100);
	}
	if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
		flapper->GetSprite().RotateBy(-100);
	}
	if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE)) {
		flapper->GetSprite().RotateBy(100);
	}*/

	//these are for adding forces
	/*if (Keyboard::Key(GLFW_KEY_W)) {
		flapper->GetRB().AddForce(Vector3(0, 20, 0));
	}
	if (Keyboard::Key(GLFW_KEY_S)) {
		flapper->GetRB().AddForce(Vector3(0, -20, 0));
	}
	if (Keyboard::Key(GLFW_KEY_A)) {
		flapper->GetRB().AddForce(Vector3(-200, 0, 0));
	}
	if (Keyboard::Key(GLFW_KEY_D)) {
		flapper->GetRB().AddForce(Vector3(200, 0, 0));
	}*/

	//These are for moving the sprite directly
	/*if (Keyboard::Key(GLFW_KEY_W)) {
	player.GetSprite().MoveUp();
	}
	if (Keyboard::Key(GLFW_KEY_S)) {
	player.GetSprite().MoveDown();
	}
	if (Keyboard::Key(GLFW_KEY_A)) {
	player.GetSprite().MoveLeft();
	}
	if (Keyboard::Key(GLFW_KEY_D)) {
	player.GetSprite().MoveRight();
	}*/
}