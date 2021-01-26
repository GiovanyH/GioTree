#include "Application.h"

std::string Application::project_name = "default";
bool Application::running = false;

void Application::init()
{
	Log::core = "[APP]";

	SDL_Init(SDL_INIT_EVERYTHING);

	Log::info("Iniciada a aplicaçao");

}

void Application::finish()
{
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
