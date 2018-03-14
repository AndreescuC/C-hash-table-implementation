#include "io_handler.h"

int readInstructions(instruction **originalInstructions, char *filename, int stdinFlag)
{
	char line[100];
	char *token;
	int reallocationIncrement = 10;
	int lineNumber = 1;
	int currentSize = 20;

	instruction *instructions;
    instructions = (instruction*)malloc(currentSize * sizeof(instruction));

    FILE* fd;
    if (stdinFlag) {
        fd = stdin;
    } else {
        char *pos;
        if ((pos=strchr(filename, '\r')) != NULL)
            *pos = '\0';
        if (strlen(filename) < 1) {
            handleFatalError(CODE_INVALID_FILENAME);
        }
        fd = fopen(filename, "r");
        if (fd == NULL) {
            handleFatalError(CODE_INVALID_FILENAME);
        }
    }

	while (fgets(line, sizeof(line), fd)) {
		token = strtok(line, " \n");

		instruction currentInstruction = initializeInstruction();
		currentInstruction.command = getCommandType(token);

		token = strtok(NULL, " \n");
		if ( token != NULL ) {
			strcpy(currentInstruction.arg1, token);
			token = strtok(NULL, " \n");
			if ( token != NULL ) {
				strcpy(currentInstruction.arg2, token);
			}
		}
		if (lineNumber >= currentSize) {
			instructions = (instruction*)realloc(
                    instructions,
                    (currentSize + reallocationIncrement)* sizeof(instruction)
            );
            currentSize += reallocationIncrement;
		}
		instructions[lineNumber - 1] = currentInstruction;
		lineNumber++;
	}

    if (!stdinFlag) {
        fclose(fd);
    }

	*originalInstructions = instructions;
	return lineNumber-1;
}

command getCommandType(char *cmdString)
{
	command cmd = INVALID_COMMAND;

	if (strcmp(cmdString, "add") == 0
        || strcmp(cmdString, "add\r") == 0){
		cmd = ADD;
	} else if (strcmp(cmdString, "remove") == 0
               || strcmp(cmdString, "remove\r") == 0) {
		cmd = REMOVE;
	} else if (strcmp(cmdString, "print") == 0
               || strcmp(cmdString, "print\r") == 0) {
		cmd = PRINT;
	} else if (strcmp(cmdString, "find") == 0
               || strcmp(cmdString, "find\r") == 0) {
		cmd = FIND;
	} else if (strcmp(cmdString, "resize") == 0
               || strcmp(cmdString, "resize\r") == 0) {
		cmd = RESIZE;
	} else if (strcmp(cmdString, "print_bucket") == 0
               || strcmp(cmdString, "print_bucket\r") == 0) {
		cmd = BPRINT;
	} else if (strcmp(cmdString, "clear") == 0
               || strcmp(cmdString, "clear\r") == 0) {
        cmd = CLEAR;
    }

	return cmd;
}