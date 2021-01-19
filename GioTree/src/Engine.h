#pragma once
#include <iostream>
#include "core.h"
#include "log.h"
#include "window.h"
#include "projectManager.h"

namespace Engine
{
	extern std::string project_name;
	extern int init();
	extern int finish();

	extern std::string dir;

	extern void Ready();
	extern void Update();
}
