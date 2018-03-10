#include "io_aux.h"

int readInstructions(instruction **originalInstructions, char *filename)
{
	char line[100];
	char *token;
	int reallocationIncrement = 10;
	int lineNumber = 1;
	int currentSize = 20;

	instruction *instructions = malloc(currentSize * sizeof(instruction));

	FILE *fd = fopen(filename, "r");
	if (fd == NULL) {
		handleFatalError(CODE_INVALID_FILENAME, 0);
	}
	
	while (fgets(line, sizeof(line), fd)) {
		token = strtok(line, " \n");

		instruction currentInstruction;
		currentInstruction.command = getCommandType(token);
		if (currentInstruction.command == INVALID_COMMAND) {
			handleFatalError(CODE_INVALID_INSTRUCTION, lineNumber);
		}
		token = strtok(NULL, " \n");
		if ( token != NULL ) {
			strcpy(currentInstruction.arg1, token);
			token = strtok(NULL, " \n");
			if ( token != NULL ) {
				strcpy(currentInstruction.arg2, token);
			}
		}
		if (lineNumber >= currentSize) {
			instructions = realloc(instructions, (size_t)(currentSize + reallocationIncrement));
		}
		instructions[lineNumber - 1] = currentInstruction;
		lineNumber++;
	}
	*originalInstructions = instructions;
	return lineNumber-1;
}

command getCommandType(char *cmdString)
{
	command cmd = INVALID_COMMAND;

	if (strcmp(cmdString, "add") == 0) {
		cmd = ADD;
	} else if (strcmp(cmdString, "remove") == 0) {
		cmd = REMOVE;
	} else if (strcmp(cmdString, "print") == 0) {
		cmd = PRINT;
	} else if (strcmp(cmdString, "find") == 0) {
		cmd = FIND;
	} else if (strcmp(cmdString, "resize") == 0) {
		cmd = RESIZE;
	} else if (strcmp(cmdString, "print_bucket") == 0) {
		cmd = BPRINT;
	}

	return cmd;
}