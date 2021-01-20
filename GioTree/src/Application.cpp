#include "Application.h"

std::string Application::project_name = "default";

window_t window(600, 400, Application::project_name);

void Application::init()
{
	Log::info("[APP]", "Iniciada a aplicaçao");

	window.title = "default"; // for now

	Core::init();
	window.init();
}

void Application::finish()
{
	SDL_DestroyWindow(window.window);
	SDL_DestroyRenderer(window.renderer);

	Core::finish();
}

int main()
{
	while(Core::running)
	{
		SDL_Event e;
		if(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				Engine::finish();
			}
		}

		SDL_RenderClear(window.renderer);
		SDL_RenderPresent(window.renderer);
		// Set window title later
	}
}
