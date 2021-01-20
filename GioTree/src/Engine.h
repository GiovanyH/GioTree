#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "core.h"
#include "log.h"
#include "window.h"
#include "projectManager.h"

namespace Engine
{
	extern std::string project_name;
	extern std::string dir;

	extern int init();
	extern int finish();
}
