#pragma once
#include <stdio.h>
#include <string>

struct GioLog
{
	static void warn(std::string warn);

	static void error(std::string error);
};
