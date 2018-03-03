void handleFatalError(int code, int line) 
{
	switch (code) {
		case CODE_INVALID_HASHTABLE_SIZE:
			logMessage(MSG_INVALID_HASHTABLE_SIZE, line);
			break;
	}
}

void logMessage(char *msg)
{
	printf("%s\n", msg);
}