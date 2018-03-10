#include "struct.h"
#include "std.h"

#ifndef TEMA1_LOG_SERVICE_H
#define TEMA1_LOG_SERVICE_H

void handleFatalError(int code, int line);
void logMessage(const char *msg, int line);

#endif
