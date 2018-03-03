void handleFatalError(int code, int line);
void logMessage(const char *msg, int line);

void handleFatalError(int code, int line) 
{
	if (code == CODE_INVALID_HASHTABLE_SIZE) {
		logMessage(MSG_INVALID_HASHTABLE_SIZE, line);
	} else if (code == CODE_INVALID_FILENAME) {
		logMessage(MSG_INVALID_FILENAME, line);
	} else if (code == CODE_INVALID_INSTRUCTION) {
		logMessage(MSG_INVALID_INSTRUCTION, line);
	}
	exit(0);
}

void logMessage(const char *msg, int line)
{
	printf("%s  at line  %d\n", msg, line);
}