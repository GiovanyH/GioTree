#pragma once
#include "log.h"
#include <GLFW/glfw3.h>

struct window_t
{
	GLFWwindow* window;
	unsigned width, height;
	char* title;
	window_t(unsigned wWidth, unsigned wHeight, char* wTitle);
	~window_t();
};
