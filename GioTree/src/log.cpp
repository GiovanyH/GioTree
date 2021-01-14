#include "log.h"

void GioLog::warn(std::string warn, std::string file, int line)
{
	printf("\033[33m[AVISO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			warn.c_str(), file.c_str(), line);
}

void GioLog::error(std::string error, std::string file, int line)
{
	printf("\033[31m[ERRO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			error.c_str(), file.c_str(), line);
	exit(1);
}
