#include "window.h"

window_t::window_t(unsigned wWidth, unsigned wHeight, std::string wTitle)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		Log::error("Nao foi possivel inicializar SDL");

	width = wWidth; height = wHeight;
	title = wTitle;
}

void window_t::init()
{
	window = SDL_CreateWindow(title.c_str(), NULL, NULL, width, height, 0);

	if(!window)
		Log::error("Nao foi possivel criar a janela");

	renderer = SDL_CreateRenderer(window, NULL, 0);

	if(!renderer)
		Log::error("Nao foi possivel criar o renderer");

}

window_t::~window_t()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}

