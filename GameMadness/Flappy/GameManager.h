#ifndef GAME_GAMEMANAGER
#define GAME_GAMEMANAGER

#include "../Engine/Engine.h"
#include "../Engine/Graphics/Sprite.h"
//#include "..//Engine/Graphics/Sprite.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"
#include "Flapper.h"
#include "InputManager.h"
#include "PipeManager.h"

#include <time.h>

class GameManager{
public:
	enum class State {
		START,
		GAMEPLAY,
		GAMEOVER,
		COUNT
	};

	GameManager();
	~GameManager();

	void Start();
private:
	Engine* mEngine;
	Flapper* mFlapper;
	PipeManager* mPipeManager;
	InputManager* mInputManager;

	Sprite mStartSprite;
	Sprite mGameOverSprite;

	State mState;

	void SetState(State state);
};

#endif

