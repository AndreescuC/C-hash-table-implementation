#include "struct.h"
#include "log_handler.h"
#include "std.h"

#ifndef TEMA1_IO_AUX_H
#define TEMA1_IO_AUX_H

int readInstructions(instruction **originalInstructions, char *filename, int stdinFlag);
command getCommandType(char *cmdString);

#endif
