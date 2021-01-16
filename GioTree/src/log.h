#pragma once
#include <sstream>
#include <chrono>
#include <ctime>
#include "core.h"

// Pra debuggar
void logWarn(const char *core, const char *warn, const char *file, unsigned line);
void logError(const char *core, const char *error, const char *file, unsigned line);
void logInfo(const char *core, const char *info);
