#pragma once
#include <sstream>
#include <chrono>
#include <ctime>
#include "core.h"

// Pra debuggar
namespace Log
{
	extern void warn(const char *core, const char *warn, const char *file, unsigned line);
	extern void error(const char *core, const char *error, const char *file, unsigned line);
	extern void info(const char *core, const char *info);
}
