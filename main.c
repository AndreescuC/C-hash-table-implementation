#include "header.h"

void printInstructions(instruction *head, int n);

int main(int argc, char *argv[])
{
	int i;
	bucket *hashTable;
	int hashTableSize = atoi(argv[1]);
	if (hashTableSize == 0) {
		handleFatalError(CODE_INVALID_HASHTABLE_SIZE, 0);
	}
	printf("Allocationg %d...\n", hashTableSize);
	hashTable = malloc(hashTableSize * sizeof(bucket));
	instruction *instructions;
	int nrOfInstructions = readInstructions(&instructions, argv[2]);
	// printInstructions(instructions, nrOfInstructions);

	// for (i=0; i<nrOfInstructions; i++) {
	// 	executeInstruction();
	// }

	return 0;
}

void printInstructions(instruction *head, int n)
{
	int i;
	printf("\n*************************PRINTING INSTRUCTIONS*************************\n");
	for (i=0; i<n; i++) {
		printf("%s-%s-%s\n", commandNames[head[i].command], head[i].arg1, head[i].arg2);
	}
	printf("*************************PRINTING INSTRUCTIONS*************************\n\n");
}