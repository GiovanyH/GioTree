#include "log.h"

/* Parte roubada do stack overflow fodase */
#define LOGGER_PRETTY_TIME_FORMAT "%Y-%m-%d %H:%M:%S"

#define LOGGER_PRETTY_MS_FORMAT ".%03d"

template <typename T>

static int to_ms(const std::chrono::time_point<T>& tp)
{
	using namespace std::chrono;

	auto dur = tp.time_since_epoch();
	return static_cast<int>(duration_cast<milliseconds>(dur).count());
}

static std::string pretty_time()
{
	auto tp = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(tp);
	std::tm* time_info = std::localtime(&current_time);

	char buffer[128];

	int string_size = strftime(
			buffer, sizeof(buffer),
			LOGGER_PRETTY_TIME_FORMAT,
			time_info
	);

	int ms = to_ms(tp) % 1000;

	string_size += std::snprintf(
			buffer + string_size, sizeof(buffer) - string_size,
			LOGGER_PRETTY_MS_FORMAT, ms
	);

	return std::string(buffer, buffer + string_size);
}
/* --------------------------------------------- */

void Log::warn(std::string core, std::string warn, std::string file, unsigned int line)
{
	printf("\033[37m%s \033[0m %s \033[33m[AVISO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			pretty_time().c_str(), core.c_str(), warn.c_str(), file.c_str(), line);
}

void Log::error(std::string core, std::string error, std::string file, unsigned int line)
{
	Core::errors = true;
	printf("\033[37m%s \033[0m %s \033[31m[ERRO]:  \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			pretty_time().c_str(), core.c_str(), error.c_str(), file.c_str(), line);
	Core::stop();
}

void Log::info(std::string core, std::string error)
{
	printf("\033[37m%s \033[0m %s \033[92m[INFO]:  \033[0m%s\n", pretty_time().c_str(), core.c_str(), error.c_str());
}
