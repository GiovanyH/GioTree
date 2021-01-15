#include "core.h"

int main()
{
	Core::init();
	Log::info("[CORE]", "sou bonito");
	Log::warn("[CORE]", "opora kkk ta funcionando", __FILE__, __LINE__);
	Log::error("[CORE]", "So de teste", __FILE__, __LINE__);
}
