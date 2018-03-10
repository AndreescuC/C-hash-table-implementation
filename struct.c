#include "struct.h"

instruction initializeInstruction()
{
	instruction in;
	in.command = INVALID_COMMAND;
	strcpy(in.arg1, "arg1");
	strcpy(in.arg2, "arg2");
	return in;
}