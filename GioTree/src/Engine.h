#pragma once

#include <iostream>
#if defined(_MSC_VER)
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <sys/wait.h>
#include "log.h"
#include "window.c"
#include "projectManager.h"

char *kiss_dire;

namespace Engine
{
	extern std::string project_name;
	extern std::string dir;

	extern int init();
	extern int finish();
}
