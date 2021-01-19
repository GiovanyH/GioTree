#include "projectManager.h"

void Project::see(std::string eDir)
{
	std::string EngineFile = eDir;

	EngineFile += "/GioTree/usr/";

	for(const auto & entry : cu::directory_iterator(EngineFile))
	{
		std::string current_path = entry.path();
		current_path.erase(current_path.begin(), current_path.begin() + EngineFile.size());
		std::cout << current_path << std::endl;
	}
}

void Project::create(std::string pName = "default", std::string pDir = "/home/user/Documents/", std::string eDir = "/home/Engine.h")
{
	std::string GameFolder = pDir + pName;

	cu::create_directories(GameFolder);

	Log::warn("[CORE]", "Seu projeto esta em", GameFolder.c_str(), 0);

	std::string GameCPP = GameFolder + "/" + pName + ".cpp";
	std::fstream fs;
    	fs.open(GameCPP, std::fstream::in | std::fstream::out | std::fstream::app);

    	fs << "#include " << '"' << eDir << "/GioTree/src/Engine.h" << '"';
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
