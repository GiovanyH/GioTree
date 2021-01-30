#pragma once
#include <string>
#include <iostream>
#include "../projectManager/projectManager.h"
#include "../UI/kiss_sdl-master/kiss_sdl.h"
#include "../UI/kiss_sdl-master/kiss_sdl.h"

struct Editor
{
	std::string projectName;
	std::string projectDescription;
	std::string projectVersion;
	void init(std::string pName, std::string pDesc, std::string pVers, std::string eDir, Project project);
	void finish();
};
