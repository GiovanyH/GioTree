#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#if defined(_MSC_VER)
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <sys/wait.h>
#include "../Log/log.h"
#include "../UI/window.c"

namespace cu = std::filesystem;

struct Project
{
	std::vector<std::string> projects;
	std::string name;
	std::string description;
	std::string version;
	std::string dir;

	void see(std::string pDirs);
	void create(std::string pName, std::string pDir, std::string eDir);
	void open(std::string dir, std::string pName);
	void remove();

	void init(std::string Engine_dir);
	void finish();
};
