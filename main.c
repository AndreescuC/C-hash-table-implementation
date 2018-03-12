#include "io_aux.h"
#include "debugging_aux.h"
#include "hash_table.h"

void mockInserts(bucket ***hashTable)
{
    char buf[12];
    int i;
    for (i=0; i<10; i++) {
        bucket* newElement;
        newElement = (bucket*)malloc(sizeof(bucket));
        sprintf(buf, "src%d", i);
        strcpy(newElement->word, buf);
        newElement->next = NULL;
        bucket *puppet;
        puppet = (*hashTable)[i % 5];
        if (puppet->word == NULL) {
            newElement->prev = NULL;
            (*hashTable)[i % 5] = newElement;
            continue;
        }
        while (puppet->next != NULL) {
            puppet = puppet->next;
        }
        printf("\n");
        newElement->prev = puppet;
        puppet->next = newElement;

    }
}

int main(int argc, char *argv[])
{
	int i;
	bucket **hashTable;
	int hashTableSize = atoi(argv[1]);
	if (hashTableSize == 0) {
		handleFatalError(CODE_INVALID_HASHTABLE_SIZE, 0);
	}
	hashTable = malloc(hashTableSize * sizeof(bucket));
	instruction *instructions;
	int nrOfInstructions = readInstructions(&instructions, argv[2]);
	printInstructions(instructions, nrOfInstructions);

	mockInserts(&hashTable);

	for (i=0; i<nrOfInstructions; i++) {
		executeInstruction(instructions[i], &hashTable, &hashTableSize);
	}

    char *c;
    gets(c);

	return 0;
}