#include "Engine.h"

std::string Engine::project_name = "default";

int main()
{
	return 0;
}

int Engine::init()
{
	Log::info("[CORE]", "test");
	return 0;
}

int Engine::finish()
{
	return 0;
}
