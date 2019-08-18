#include "PipeManager.h"
#include "../Engine/Engine.h"
#include "../Engine/Physics/Rigidbody.h"

PipeManager::PipeManager() :
	xStartSeparation(800),
	yStartSeparation(500),
	xSeparation(xStartSeparation),
	ySeparation(yStartSeparation),
	minXSeparation(200),
	minYSeparation(300),
	xSeparationSpeed(10),
	ySeparationSpeed(10),
	minSpawnY(284),
	maxSpawnY(Engine::SCREEN_HEIGHT - 284),
	totalPipes(0),
	points(0)
{
	Pipe::Initialize();
	CreatePipe();
	//pipes.push_back(new Pipe(Vector3(1200, Engine::SCREEN_HEIGHT / 2, 0)));
	//pipes.push_back(new Pipe(Vector3(2400, Engine::SCREEN_HEIGHT / 2, 0)));
}

PipeManager::~PipeManager()
{
	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}
}

void PipeManager::Update() {
	vector<int> pipesToDelete;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->Update();
		if (pipes[i]->GetX() < -(pipes[i]->GetWidth() / 2)) { //if the pipe went off the screen
			pipesToDelete.push_back(i);
		}

		if (i == pipes.size() - 1) { //if we're on the last pipe
			if (pipes[i]->GetX() < Engine::SCREEN_WIDTH - xSeparation) {
				CreatePipe();
			}
		}

		//if we just crossed the middle of the screen, we score a point
		if (pipes[i]->GetX() < Engine::SCREEN_WIDTH / 2 &&
			pipes[i]->GetPrevPos() > Engine::SCREEN_WIDTH / 2) 
		{
			points++;
		}

		//TODO: draw points on screen, GLFW doesn't do that
		//recommended library: freetype, load ttf fonts or real time fonts and render them to the screen
		//https://www.freetype.org/
		cout << "Points: " << points << endl;

	}

	for (unsigned int i = 0; i < pipesToDelete.size(); i++) {
		delete pipes[pipesToDelete[i]];
		pipes.erase(pipes.begin() + pipesToDelete[i]); //why begin?
	}

	
}

void PipeManager::Render() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->Render();
	}
}

bool PipeManager::CheckCollission(Flapper& flapper) {
	bool isColliding = false;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		isColliding = Rigidbody::IsColliding(flapper.GetRB(), pipes[i]->GetTopRB()) ||
					  Rigidbody::IsColliding(flapper.GetRB(), pipes[i]->GetBotRB());

		if (isColliding)
			break;
	}
	return isColliding;
}

void PipeManager::CreatePipe() {
	float spawnY = (rand() % (maxSpawnY - minSpawnY)) + minSpawnY;

	Pipe* pipe = new Pipe(Vector3(Engine::SCREEN_WIDTH, spawnY, 0));
	pipe->SetGap(ySeparation);
	pipes.push_back(pipe);
	totalPipes++;

	if (totalPipes % 2 == 0) { //makes game harder
		if (xSeparation > minXSeparation + xSeparationSpeed) {
			xSeparation -= xSeparationSpeed;
		}
		if (ySeparation > minYSeparation + ySeparationSpeed) {
			ySeparation -= ySeparationSpeed;
		}
	}
}

void PipeManager::Reset() {
	//pipes.erase(pipes.begin(), pipes.end());
	int size = pipes.size();
	for (unsigned int i = 0; i < size; i++) {
		delete pipes[i];
	}
	pipes.clear();
	
	xSeparation = xStartSeparation;
	ySeparation = yStartSeparation;
	//xSeparationSpeed = 10;
	//ySeparationSpeed = 10;
	totalPipes = 0;
	points = 0;
	CreatePipe();
}