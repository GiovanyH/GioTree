#include "core.h"
#include "log.h"
#include "window.h"
#include "projectManager.h"
#include <iostream>

namespace Engine
{
	extern std::string project_name;
	extern int init();
	extern int finish();

	extern void Ready();
	extern void Update();
}
