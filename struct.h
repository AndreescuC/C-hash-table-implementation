const int CODE_INVALID_HASHTABLE_SIZE = 0;
const int CODE_INVALID_FILENAME = 1;
const int CODE_INVALID_INSTRUCTION = 2;

const int MSG_INVALID_HASHTABLE_SIZE = "Invalid hash table size provided";
const int MSG_INVALID_FILENAME = "Invalid input filename provided";
const int MSG_INVALID_INSTRUCTION = "Invalid instruction provided";

typedef struct bucket {
	char value[100];
	struct bucket *next;
	struct bucket *prev;
}bucket;

typedef enum command {ADD, REMOVE, FIND, PRINT, BPRINT, RESIZE, INVALID_COMMAND}command;

typedef struct instruction {
	enum command command;
	char arg1[10];
	char arg2[10];
}instruction;