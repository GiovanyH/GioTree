#include "Engine.h"

std::string Engine::project_name = "default";

int main()
{
	Engine::Ready();
	Engine::Update();
	return 0;
}

int Engine::init()
{
	Log::info("[CORE]", "test");
	std::cin >> project_name;
	return 0;
}

int Engine::finish()
{
	return 0;
}
