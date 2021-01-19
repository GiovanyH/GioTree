#include "projectManager.h"

void Project::create(std::string pName = "default", std::string pDir = "/home/user/Documents/", std::string eDir = "/home/Engine.h")
{
	std::string GameFolder = pDir + pName;

	namespace cu = std::filesystem;
	cu::create_directories(GameFolder);

	Log::warn("[CORE]", "Seu projeto esta em", GameFolder.c_str(), 0);

	std::string GameCPP = GameFolder + "/" + pName + ".cpp";
	std::fstream fs;
    	fs.open(GameCPP, std::fstream::in | std::fstream::out | std::fstream::app);

    	fs << "#include " << '"' << eDir << '"';
	fs << "\n\nEngine::Ready()\n{\n}\n\nEngine::Update()\n{\n}\n\n// Teste\n";

    	fs.close();
}

void Project::open(std::string pName)
{

}

void Project::remove()
{
	std::string rmGameFolder = "rm -r " + dir;

	system(rmGameFolder.c_str());
}
