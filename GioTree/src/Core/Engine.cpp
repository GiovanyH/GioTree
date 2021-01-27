#include "Engine.h"

std::string Engine::dir = cu::current_path();

int Engine::init()
{
	Project project;
	project.init(dir);
	project.finish();
	std::cout << "Project finalized" << std::endl;
	/*Log::info("Engine iniciada!");
	Project project;     
        unsigned opt = 0;	
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
	}*/

	return 0;
}

int Engine::finish()
{
	Log::info("Engine finalizada!");
	return 0;
}

int main()
{
	Engine::init();
	return 0;
}
