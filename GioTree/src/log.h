#pragma once
#include <stdio.h>
#include <string>

struct GioLog
{
	static void warn(std::string warn, std::string file, int line);

	static void error(std::string error, std::string file, int line);
};
