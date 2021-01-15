#include "log.h"

void GioLog::warn(std::string core, std::string warn, std::string file, unsigned int line)
{
	printf("%s \033[33m[AVISO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			core.c_str(), warn.c_str(), file.c_str(), line);
}

void GioLog::error(std::string core, std::string error, std::string file, unsigned int line)
{
	GioCore::error = true;
	printf("%s \033[31m[ERRO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			core.c_str(), error.c_str(), file.c_str(), line);
}

void GioLog::info(std::string core, std::string error, std::string file = "default", unsigned int line = 0)
{
	if (file == "default")
		printf("%s \033[92m[INFO]: \033[0m%s\n", core.c_str(), error.c_str());
	else
		printf("%s \033[92m[INFO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			core.c_str(), error.c_str(), file.c_str(), line);
}
