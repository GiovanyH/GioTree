#pragma once
#include "log.h"

struct Core
{
	static unsigned errors;
	static bool running;
	static void init();
	static void stop();
};
