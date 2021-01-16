#include "core.h"
#include "log.h"

int main()
{
	Core::init();
	logInfo("[CORE]", "sou bonito");
	logWarn("[CORE]", "opora kkk ta funcionando", __FILE__, __LINE__);
	logError("[CORE]", "So de teste", __FILE__, __LINE__);
}
