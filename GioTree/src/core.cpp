#include "core.h"

unsigned Core::errors = 0;
bool Core::running = false;

void Core::init()
{
	running = true;
	logInfo("[CORE]", "Engine iniciada!");
}

void Core::stop()
{
	running = false;
	char p3[35];
	snprintf(p3, sizeof(p3), "Engine terminada com %u erros!", errors);
		
	logInfo("[CORE]", p3);
}
