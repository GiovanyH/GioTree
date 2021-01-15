#include "core.h"

bool Core::errors = false;
bool Core::running = true;

void Core::init()
{
	Log::info("[CORE]", "Engine iniciada!");
}

void Core::stop()
{
	Core::running = false;
	
	if(Core::errors)
		Log::info("[CORE]", "Engine terminada com erros :(");
	else
		Log::info("[CORE]", "Engine terminada com sucesso :)");
}
