#ifndef GAME_PIPEMANAGER
#define GAME_PIPEMANAGER

#include "Pipe.h"
#include <vector>
#include "Flapper.h"

class PipeManager
{

public:
	PipeManager();
	~PipeManager();

	void Update();
	void Render();

	bool CheckCollission(Flapper& flapper);

private:
	void CreatePipe();
	vector<Pipe*> pipes;
	
	float xSeparation;
	float minXSeparation;
	float ySeparation;
	float minYSeparation;
	float xSeparationSpeed;
	float ySeparationSpeed;

	int minSpawnY;
	int maxSpawnY;

	int totalPipes;
};

#endif
