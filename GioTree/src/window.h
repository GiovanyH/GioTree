#pragma once
#include "log.h"
// Evitar conflitos com os header
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct window_t
{
	GLFWwindow* window;
	unsigned width, height;
	std::string title;
	window_t(unsigned wWidth, unsigned wHeight, std::string wTitle);
	void init();
	~window_t();
};
