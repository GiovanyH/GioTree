#pragma once
#include "log.h"

struct Core
{
	static bool errors;

	static bool running;

	static void init();

	static void stop();
};
