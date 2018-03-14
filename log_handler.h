#include "struct.h"
#include "std.h"

#ifndef TEMA1_LOG_SERVICE_H
#define TEMA1_LOG_SERVICE_H

#define DIE(assertion, call_description)		\
	do {								        \
		if (assertion) {					    \
			fprintf(stderr, "(%s, %d): ",		\
					__FILE__, __LINE__);		\
			perror(call_description);			\
			exit(errno);					    \
		}							            \
	} while (0)

void handleFatalError(int code);

#endif
