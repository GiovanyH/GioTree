#include "window.h"

window_t::window_t(unsigned wWidth, unsigned wHeight, std::string wTitle)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		Log::error("[CORE]", "Nao foi possivel inicializar SDL", __FILE__, __LINE__);

	width = wWidth; height = wHeight;
	title = wTitle;
}

void window_t::init()
{
	window = SDL_CreateWindow(title.c_str(), NULL, NULL, width, height, 0);

	if(!window)
		Log::error("[CORE]", "Nao foi possivel criar a janela", __FILE__, __LINE__);

	renderer = SDL_CreateRenderer(window, NULL, 0);

	if(!renderer)
		Log::error("[CORE]", "Nao foi possivel criar o renderer", __FILE__, __LINE__);

}

window_t::~window_t()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}

