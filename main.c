#include "header.h"

int main(int argc, char *argv[])
{
	int i;
	bucket **hashTable;
	int hashTableSize = atoi(argv[1]);
	if (hashTableSize == 0) {
		handleFatalError(CODE_INVALID_HASHTABLE_SIZE, 0);
	}
	printf("Allocationg %d...\n", hashTableSize);
	hashTable = malloc(hashTableSize * sizeof(bucket));
	instruction *instructions;
	int nrOfInstructions = readInstructions(&instructions, argv[2]);
	printInstructions(instructions, nrOfInstructions);

	/*for (i=0; i<nrOfInstructions; i++) {
		executeInstruction(instructions[i], &hashTable, &hashTableSize);	
		printHashTable(hashTable, hashTableSize);
	}*/
	char buf[12];
	for (i=0; i<14; i++) {

		bucket* newElement;
		newElement = (bucket*)malloc(sizeof(bucket));
		sprintf(buf, "dest%d", i);
		strcpy(newElement->word, buf);
		newElement->next = NULL;
		bucket *puppet = hashTable[i % 5];

		if (puppet == NULL) {
			newElement->prev = NULL;	
			hashTable[i % 5] = newElement;
			continue;
		}
		while (puppet->next != NULL) {
			puppet = puppet->next;
		}
		newElement->prev = puppet;
		puppet->next = newElement;
	
	}
	//printHashTable(hashTable, hashTableSize);
	executeInstruction(instructions[i], &hashTable, hashTableSize);
	//printHashTable(hashTable, hashTableSize);

	return 0;
}