#pragma once
#include <iostream>

struct GioLog
{
	static void printWarn(std::string warn);

	static void printError(std::string error);
};
