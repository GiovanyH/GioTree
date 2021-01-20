#include "log.h"

// Formato de tempo pra agradar os olhos 
#define LOGGER_PRETTY_TIME_FORMAT "%Y-%m-%d %H:%M:%S"
// Formato pro printf
#define LOGGER_PRETTY_MS_FORMAT ".%03d"

// Converter o tempo atual pra milisegundos pq s
template<typename T>
int to_ms(const std::chrono::time_point<T>& tp)
{
	auto dur = tp.time_since_epoch();
	return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(dur).count());
}

// Formatar ele em duas partes: a parte da data mesmo e a parte com milisegundos
std::string pretty_time()
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
// 2020-01-15 21:00:32.682 format

std::string Log::core = "[CORE]";
void Log::warnf(const char *mess, const char *file, unsigned line)
{
	printf("\033[37m%s \033[0m %s \033[33m[AVISO]: \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			pretty_time().c_str(), core.c_str(), mess, file, line);
}

void Log::errorf(const char *mess, const char *file, unsigned line)
{
	Core::errors++;
	printf("\033[37m%s \033[0m %s \033[31m[ERRO]:  \033[0m%s, \033[36m[%s, linha %i]\033[0m\n",
			pretty_time().c_str(), core.c_str(), mess, file, line);
}

void Log::info(const char *mess)
{
	printf("\033[37m%s \033[0m %s \033[92m[INFO]:  \033[0m%s\n", pretty_time().c_str(), core.c_str(), mess);
}
