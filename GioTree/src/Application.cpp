#include "Application.h"

std::string Application::project_name = "default";

window_t window(600, 400, Application::project_name);

void Application::init()
{
	Log::core = "[APP]";

	Core::init();
	window.init();

	Log::info("Iniciada a aplicaçao");

	window.title = project_name.c_str(); 
}

void Application::finish()
{
	SDL_DestroyWindow(window.window);
	SDL_DestroyRenderer(window.renderer);

	Core::finish();
}

int main()
{
	Application::init();

	while(Core::running)
	{
		SDL_Event e;
		if(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				Application::finish();
			}
		}
		SDL_RenderClear(window.renderer);
		SDL_RenderPresent(window.renderer);
	}
}
