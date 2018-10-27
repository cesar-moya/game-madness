#ifndef GAME_INPUTMANAGER
#define GAME_INPUTMANAGER

#include "Flapper.h"
#include "../Engine/Engine.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"

class InputManager {

public:
	InputManager(Flapper* _flapper);
	void Update();
	

private:
	Flapper* flapper;

};

#endif
