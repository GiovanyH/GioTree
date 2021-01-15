#pragma once
#include "log.h"

struct GioCore
{
	static bool error;

	static bool running;

	static void init();

	static void stop();
};
