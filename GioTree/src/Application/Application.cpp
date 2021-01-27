#include "Application.h"

std::string Application::project_name = "default";
bool Application::running = false;

SDL_Window* window;
SDL_Renderer* renderer;

void Application::init()
{
	Log::core = "[APP]";

	SDL_Init(SDL_INIT_EVERYTHING);

	Log::info("Iniciada a aplicaçao");

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(project_name.c_str(), NULL, NULL, 600, 400, 0);
	renderer = SDL_CreateRenderer(window, SDL_RENDERER_ACCELERATED, 0);
}

void Application::finish()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	running = false;
}

int main()
{
	Application::running = true;
	Application::init();

	while(Application::running)
	{
		SDL_Event e;
		if(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				Application::finish();
			}
		}
	}
}
