#pragma once
#include <string>
#include <iostream>

struct Editor
{
	std::string projectName;
	std::string projectDescription;
	std::string projectVersion;
	void init(std::string pName, std::string pDesc, std::string pVers);
	void finish();
};
