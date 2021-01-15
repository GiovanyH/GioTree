#include "core.h"

bool GioCore::error = false;
bool GioCore::running = true;

void GioCore::init()
{
	GioLog::info("[CORE]", "Engine iniciada!", "default", 0);
}

void GioCore::stop()
{
	GioCore::running = false;
	
	if(GioCore::error)
		GioLog::info("[CORE]", "Engine terminada com erros :(", "default", 0);
	else
		GioLog::info("[CORE]", "Engine terminada com sucesso!", "default", 0);
}
