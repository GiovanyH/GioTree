#include "core.h"

bool Core::running = false;
unsigned Core::errors = 0;

void Core::init()
{
	running = true;
	Log::info("[CORE]", "Engine iniciada!");
}

void Core::stop()
{
	running = false;
	char p3[35];
	snprintf(p3, sizeof(p3), "Engine terminada com %u erros!", errors);
		
	Log::info("[CORE]", p3);
}
