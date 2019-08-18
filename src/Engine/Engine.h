#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "GLFW\glfw3.h"  //the actual game engine?
#pragma comment(lib, "opengl32.lib") //linking the library, make sure it's 32bit, also up there in the x86 project settings

#include <iostream>

using namespace std;

///This should be a singleton
class Engine{

public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	static float GetDT(); //get delta time

	Engine();
	~Engine();
	bool Initialize(const char* windowTitle);

	//usually the following functs happen in that order, you update the state
	//of something in the background, then you render it.
	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	
	//delta time, the time it took for a frame / cycle to complete. we'll multiply this by the speed to enusure everything moves at a constant rate 
	//regardless of whether you have a faster machine
	static float dt; 
	float lastTime; //last time anything happened, in miliseconds

};

#endif