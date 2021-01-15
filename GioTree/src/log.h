#pragma once
#include <sstream>
#include <string>
#include "core.h"

struct GioLog
{
	static void warn(std::string core, std::string warn, std::string file, unsigned int line);

	static void error(std::string core, std::string error, std::string file, unsigned int line);

	static void info(std::string core, std::string info, std::string file, unsigned int line);
};
