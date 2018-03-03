instruction *readInstructions(instruction *instructions, char *filename)
{
	char line[100];
	char token[15];
	int reallocationIncrement = 10;
	int lineNumber = 1;

	instructions = malloc(10 * sizeof(instruction));

	FILE *fd = fopen(filename, "r");
	if (fd == NULL) {
		handleFatalError(CODE_INVALID_FILENAME, 0);
	}

	while (fgets(line, sizeof(line), fd)) {
		token = strtok(line, " ");
		instruction currentInstruction;
		currentInstruction.command = getCommandType(token);
		if (currentInstruction.command == INVALID_COMMAND) {
			handleFatalError(CODE_INVALID_INSTRUCTION, lineNumber);
		}
		while( token != NULL ) {
			
			token = strtok(NULL, " ");
		}
		lineNumber++;
	}
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
	} else if (strcmp(cmdString, "find")) {
		cmd = FIND;
	} else if (strcmp(cmdString, "resize")) {
		cmd = RESIZE;
	} else if (strcmp(cmdString, "print_bucket")) {
		cmd = BPRINT;
	}

	return cmd;
}