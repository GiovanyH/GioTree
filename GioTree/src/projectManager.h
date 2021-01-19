#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include "log.h"

namespace cu = std::filesystem;

struct Project
{
	std::string name;
	std::string description;
	std::string version;
	std::string dir;

	void see(std::string dir);
	void create(std::string pName, std::string pDir, std::string eDir);
	void open(std::string pName);
	void remove();
};
