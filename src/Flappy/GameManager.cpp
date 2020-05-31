#include "GameManager.h"


GameManager::GameManager() {
	srand(time(NULL)); //used on pipeManager rand() function, a sort of initializer
	mEngine = new Engine();
	const char* title = "GameMadness";
	mEngine->Initialize(title);
	Sprite biplane = Sprite("Assets/Art/biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	biplane.SetScale(0.15f);
	mFlapper = new Flapper(biplane);
	mPipeManager = new PipeManager();
	mInputManager = new InputManager(mFlapper);
	mStartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite.SetScale(0.15f);
	SetState(State::START);
}

GameManager::~GameManager() {
	delete mEngine;
	delete mFlapper;
	delete mPipeManager;
	delete mInputManager;
}

void GameManager::Start() {
	while (true) {
		if (Keyboard::KeyDown(GLFW_KEY_ESCAPE)) {
			break;
		}

		mEngine->Update(); //makes sure we can poll those events so we can move the screen around
		
		switch (mState) {
			case State::START: {
				cout << "Waiting for the user to start the game.." << endl;
				mEngine->BeginRender();
				mStartSprite.Render();
				mEngine->EndRender();

				//TODO: move this keyboard stuff to the input manager...
				if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
					SetState(State::GAMEPLAY);
				}
			}
			break;
			case State::GAMEPLAY: {
				//cout << "Playing..." << endl;
				mFlapper->Update();
				mPipeManager->Update();
				
				//bool isColliding = Rigidbody::IsColliding(player.GetRB(), pipe.GetTopRB()) || Rigidbody::IsColliding(player.GetRB(), pipe.GetBotRB());
				//cout << (isColliding ? "COLLIDING!!" : "....") << endl;
				//handling input, this moves the sprite along with the mouse movement
				//testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY()); 
				mInputManager->Update();
				//make sure to clear that back buffer, draw clear color and swap it
				mEngine->BeginRender();
				mPipeManager->Render();
				mFlapper->Render();
				mEngine->EndRender();

				bool isDead = mPipeManager->CheckCollission(*mFlapper);
				float y = mFlapper->GetSprite().GetPos()->y;
				if (y > Engine::SCREEN_HEIGHT || y < 0)
					isDead = true;
				
				if (isDead) {
					//cout << (isColliding ? "You collided, GAME OVER!" : "...") << endl;
					SetState(State::GAMEOVER);
				}
			}
			break;
			case State::GAMEOVER: {
				cout << "GAME OVER!, Press SPACE to start again." << endl;
				mEngine->BeginRender();
				mPipeManager->Render();
				mFlapper->Render();
				mGameOverSprite.Render();
				mEngine->EndRender();

				//TODO: move this keyboard stuff to the input manager...
				if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
					mFlapper->Reset();
					mPipeManager->Reset();
					SetState(State::GAMEPLAY);
				}
			}
			break;
			default:
				cout << "Unhandled game state: " << static_cast<int>(mState) << endl;
			break;
		}
		
		
	}
}

void GameManager::SetState(State state) {
	mState = state;
	//if (mState == State::GAMEPLAY) {
	//	mFlapper->Reset();
	//	//mPipeManager->Reset();
	//}
}