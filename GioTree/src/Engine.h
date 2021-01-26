#pragma once

#include <iostream>
#include <sys/wait.h>
#include "log.h"
#include "projectManager.h"

char *kiss_dire;

namespace Engine
{
	extern std::string dir;

	extern int init();
	extern int finish();
}
