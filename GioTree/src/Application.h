#include <string>
#include "log.h"
#include <SDL2/SDL.h>

namespace Application
{
	extern bool running;
	extern std::string project_name;

	extern void init();

	extern void Ready();
	extern void Update();

	extern void finish();
}
