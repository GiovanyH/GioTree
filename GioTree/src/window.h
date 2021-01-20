#pragma once
#include "log.h"
#include <SDL2/SDL.h>

struct window_t
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	unsigned width, height;
	std::string title;
	window_t(unsigned wWidth, unsigned wHeight, std::string wTitle);
	void init();
	~window_t();
};
