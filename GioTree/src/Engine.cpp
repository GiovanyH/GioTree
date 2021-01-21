#include "Engine.h"

std::string Engine::dir = cu::current_path();
std::string Engine::project_name = "default";
std::string wDir = (Engine::dir + "/GioTree/src/kiss_sdl-master/");

window_t window[1];

int Engine::init()
{
	Log::core = "[CORE]";
	Log::info(dir.c_str());

	window->width = 600; window->height = 400;
	Log::info("window->width = 600,");

	Project project;     
        project.see(dir);                                    
        unsigned opt = 0;	
	if(project.projects.size() > 0)
	{
        	std::cout << "Selecione uma opçao:" << std::endl; 
        	for(int p = 0; p < project.projects.size(); ++p)
        	{
               		std::cout << "[" << p << "] - " << project.projects.at(p) << std::endl;
        	}

        	std::cout << "[" << project.projects.size() << "] - Novo projeto" << std::endl;
        	std::cout << ">> ";
        	std::cin >> opt;
	}
	if(project.projects.size() == 0 or opt == project.projects.size())
	{
		std::cout << "Criando um projeto!" << std::endl;
		std::string pName;
		std::cout << "Nome do projeto: ";
		std::cin >> pName;
		std::string pDir;
                std::cout << std::endl << "Diretorio do projeto: ";
		std::cin >> pDir;

                std::cout << std::endl;

                project.create(pName, pDir, dir);
        }
	else if(project.projects.size() > 0 && opt < project.projects.size())
	{
		Log::info("Choosing project");
		project.open(dir, project.projects.at(opt));
	}

	Log::info("Choosed");

	project_name = project.projects.at(opt);

	Log::info("project name = project.at(opt)");

	window->title = (char*)malloc(sizeof(project_name.c_str()));
	strcpy(window->title, project_name.c_str());

	Log::info("strcpy window title");

	Core::init();
	window->init(wDir.c_str());
	
	Log::info("Engine inicializada!");

	std::string eDir = dir + "/GioTree/src/";
	std::string libs = eDir + "Application.cpp " + eDir + "log.cpp " + eDir + "window.cpp " + eDir + "core.cpp " + "-lSDL2";
	std::string pCPP = "g++ -w " + project.dir + "/" + project.name + ".cpp " + libs + " -o " + project.name;

	system(pCPP.c_str());

	int pid, status;

   	if (pid = fork()) { waitpid(pid, &status, 0); /* wait for the child to exit */ } 

	else { execl(project.name.c_str(), project.name.c_str(), NULL); }

	return 0;
}

int Engine::finish()
{
	Core::finish();
	return 0;
}

int main()
{
	Engine::init();

	int draw = 1;
	while(Core::running)
	{
		SDL_Event e;
		if(SDL_PollEvent(&window->e))
		{
			if(window->e.type == SDL_QUIT) Engine::finish();
			
			kiss_window_event(window->window, &window->e, &draw);
		}

		if(!draw) continue;
		SDL_RenderClear(window->renderer);

		kiss_window_draw(window->window, window->renderer);
		SDL_RenderPresent(window->renderer);
	}
	kiss_clean(&window->objects);
	return 0;
}
