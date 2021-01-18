#pragma once
#include <fstream>
#include <unistd.h>
#include "log.h"

struct Project
{
	std::string name;
	std::string description;
	std::string version;
	std::string dir;

	void create(std::string pName, std::string pDir);
	void remove();
};
