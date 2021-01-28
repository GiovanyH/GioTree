#include "editor.h"

void Editor::init(std::string pName, std::string pDesc, std::string pVers)
{
	projectName = pName;
	projectDescription = pDesc;
	projectVersion = pVers;

	std::cout << projectName << std::endl;
	std::cout << projectDescription << std::endl;
	std::cout << projectVersion << std::endl;

	// init
}

void Editor::finish() {}
