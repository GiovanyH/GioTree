#include "log.h"

void GioLog::printWarn(std::string warn)
{
	printf("\033[33m[AVISO]: \033[0m%s\n", warn.c_str());
}

void GioLog::printError(std::string error)
{
	printf("\033[31m[ERRO]: \033[0m%s\n", error.c_str());
}
