#include "header.h"

void main(int argc, char *argv[])
{
	bucket *hashTable;
	int hashTableSize = atoi(argv[1]);
	if (hashTableSize == 0) {
		handleFatalError(CODE_INVALID_HASHTABLE_SIZE)
	}

	hashTable = malloc(hashTableSize * sizeof(bucket));
	instruction *instructions;
	readInstructions(instructions, argv[2]);
}