#pragma once
#include <sstream>
#include <chrono>
#include <ctime>
#include "core.h"

// Pra debuggar
struct Log
{ 
	static void warn(const char* core, const char* warn, const char* file, unsigned line);

	static void error(const char* core, const char* error, const char* file, unsigned line);

	static void info(const char* core, const char* info);
};
