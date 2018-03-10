#include "struct.h"
#include "log_service.h"
#include "std.h"

#ifndef TEMA1_IO_AUX_H
#define TEMA1_IO_AUX_H

int readInstructions(instruction **originalInstructions, char *filename);
command getCommandType(char *cmdString);

#endif
