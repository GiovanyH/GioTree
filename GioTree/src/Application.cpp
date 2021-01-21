#include "Application.h"

std::string Application::project_name = "default";

void Application::init()
{
	Log::core = "[APP]";

	Core::init();

	Log::info("Iniciada a aplicaçao");

}

void Application::finish()
{
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
	}
}
