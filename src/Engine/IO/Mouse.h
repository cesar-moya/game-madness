#ifndef GAME_MOUSE
#define GAME_MOUSE

#include "GLFW/glfw3.h"

//static, you don't really want to instanciate more than one class of a Mouse or Keyboard b/c you don't have many
class Mouse {

public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static double GetMouseX();
	static double GetMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button); //button status

private:
	static double x;
	static double y;
	
	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];

};

#endif

