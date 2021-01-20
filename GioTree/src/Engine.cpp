#include "Engine.h"

std::string Engine::dir = cu::current_path();
window_t window(600, 400, "GioEngine");

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

int Engine::init()
{
	Project project;     
                         
        project.see(dir);                                    
                                                              
        unsigned opt;                                

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
        if(opt == project.projects.size()-1 || project.projects.size() <= 0)                           
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
	Core::init();
	window.init();
	

	return 0;
}

int Engine::finish()
{
	Core::finish();
	return 0;
}
