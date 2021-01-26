#include "projectManager.h"

void Project::see(std::string pDirs)
{
	std::string EngineFile = pDirs + "/GioTree/usr/";

	for(const auto & entry : cu::directory_iterator(EngineFile))
	{
		std::string current_path = entry.path();
		current_path.erase(current_path.begin(), current_path.begin() + EngineFile.size());

		std::string extension = current_path;
		extension.erase(extension.begin(), extension.end()-4);
		if(extension == ".gio")
			projects.push_back(current_path);
	}
}

void Project::create(std::string pName = "default", std::string pDir = "/home/user/Documents/", std::string eDir = "/home/GioTree/GioTree/src/Engine.h")
{
	std::string GameFolder = pDir + pName;
	cu::create_directories(GameFolder);
	dir = GameFolder;
	name = pName;

	Log::info(("Seu projeto esta em" + GameFolder).c_str());

	std::string GameCPP = GameFolder + "/" + pName + ".cpp";
	std::fstream fs(GameCPP, std::fstream::in | std::fstream::out | std::fstream::app);
    	fs << "#include " << '"' << eDir << "/GioTree/src/Application.h" << '"';
	fs << "\n\nvoid Application::Ready()\n{\n}\n\nvoid Application::Update()\n{\n}\n\n// Teste\n";
    	fs.close();

	std::string EngineFile = eDir + "/GioTree/usr/" + pName + ".gio";

	std::fstream fs2(EngineFile, std::fstream::in | std::fstream::out | std::fstream::app);
	fs2 << "GioDir: " << dir << "\nGioName: " << name << "\nGioDesc: " << description << "\nGioVersion: " << version;
	fs2.close();
}

void Project::open(std::string dataDir, std::string pName)
{
	std::string line;
	std::string pPath = dataDir + "/GioTree/" + "usr/" + pName;
	std::cout << pPath << std::endl;
	std::fstream fs(pPath, std::fstream::in | std::fstream::out | std::fstream::app);
	std::vector<std::string> projProp;

	while(getline(fs, line))
	{
		std::cout << line << std::endl;
		projProp.push_back(line);
	}
	fs.close();

	std::cout << projProp.at(0);
	dir = projProp.at(0);
	name = projProp.at(1);
	description = projProp.at(2);
	version = projProp.at(3);

	dir.erase(0, 8);
	name.erase(0, 9);
	description.erase(0, 9);
	version.erase(0, 12);

	std::cout << dir << std::endl;
	std::cout << name << std::endl;
	std::cout << description << std::endl;
	std::cout << version << std::endl;
}

void Project::remove()
{
	std::string rmGameFolder = "rm -r " + dir;

	system(rmGameFolder.c_str());
}
