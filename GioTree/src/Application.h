#pragma once

#include <string>
#include "log.h"
#include "core.h"
#include "window.h"

namespace Application
{
	extern std::string project_name;

	extern void init();

	extern void Ready();
	extern void Update();

	extern void finish();
}
