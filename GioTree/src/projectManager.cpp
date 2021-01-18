#include "projectManager.h"

void Project::create(std::string pName = "default", std::string pDir = "~/Documents/")
{
	std::string mkGameFolder = "mkdir " + pDir + pName;

	Log::warn("[CORE]", "Seu projeto esta em", std::string(pDir + pName).c_str(), 0);

	dir = pDir + pName;

	std::string gameCppFile = "touch " + dir + "/" + pName + ".cpp";

	system(mkGameFolder.c_str());
	system(gameCppFile.c_str());
}

void Project::remove()
{
	std::string rmGameFolder = "rm -r " + dir;

	system(rmGameFolder.c_str());
}
