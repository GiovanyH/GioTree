#pragma once
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include "core.h"

struct Log
{
	static void warn(std::string core, std::string warn, std::string file, unsigned int line);

	static void error(std::string core, std::string error, std::string file, unsigned int line);

	static void info(std::string core, std::string info);
};
