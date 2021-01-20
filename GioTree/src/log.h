#pragma once
#include <sstream>
#include <chrono>
#include <ctime>
#include "core.h"

// Pra debuggar
namespace Log
{
	extern std::string core;
	extern void warnf(const char *mess, const char *file, unsigned line);
	#define warn(mess) warnf(mess,__FILE__, __LINE__)
	extern void errorf(const char *mess, const char *file, unsigned line);
	#define error(mess) errorf(mess,__FILE__,__LINE__)
	extern void info(const char *mess);
}
