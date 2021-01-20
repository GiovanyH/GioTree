#include "Engine.h"

std::string Engine::dir = cu::current_path();

window_t window(600, 400, "GioEngine");

int Engine::init()
{
	Log::core = "[CORE]";

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
		project.open(dir, project.projects.at(opt));
	}

	Core::init();
	window.init();
	
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
	}
	return 0;
}

