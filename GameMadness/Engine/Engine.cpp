#include "Engine.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::Initialize(const char* windowTitle) {
	//we're setting up a context of what we're going to use
	if (!glfwInit()) {
		cout << "Error initializing GLFW" << endl;
		return false;
	}
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}

	//GLFW Setup
	glfwMakeContextCurrent(window);
	//There is a separation between the screen width and height and the window (frame buffer) width and height
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	//in glfw there is double buffering, one is what's being shown, the other one is where you draw, then you swap them
	glfwSwapInterval(1); //secs

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	
	//center the window
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup
	//setup viewport using sizes from buffer size
	glViewport(0, 0, width, height);
	
	//the projection matrix
	//GL is a state machine, as you call functions it changes the state of the state machine at that time, so this next 
	//MatrixMode(GL_PROJECTION) the next functions executed are for this mode, until the next mode happens
	glMatrixMode(GL_PROJECTION); //for 2D this works fine currently, there are others you can use, see GL wiki
	glLoadIdentity(); //loads a blank identity matrix, before you start rotating camera etc.
	//orthographic camera
	glOrtho(0, width, 0, height, -10, 10); //the last 2 don't matter as much b/c we're on 2D
	glDepthRange(-10, 10);
	
	//This is the next mode, following functions will be executed based on this mode now
	glMatrixMode(GL_MODELVIEW); //this is how we load our 2D's

	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	return true;
}

void Engine::Update() {
	//allow glfw to allow all events to stack in the queue, like hovering mouse, etc
	glfwPollEvents();
}

void Engine::BeginRender() {
	//remember the double buffer, we render on the back buffer and once done you swap it.
	//first we clear the buffer, we don't want to draw on top of old buffers
	glClearColor(0.5, 1, 0.5, 1); //green
	
	//sicne we're doing depth, we need to clear depth buffer bit, it's a way for open gl to clear the bits it uses to keep track of 
	//the bits and colors of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//begin draw here
	//call EndRender when done to end draw
}

void Engine::EndRender() {
	glfwSwapBuffers(window); 
	//anything drawn after this will never be seen by human eyes
}