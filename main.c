#include "io_handler.h"
#include "hash_table.h"

int main(int argc, char *argv[])
{
    int i, j, nrOfInstructions, stdinFlag = 0;
    bucket **hashTable;
    unsigned int hashTableSize = (unsigned int)atoi(argv[1]);
    if (hashTableSize == 0) {
        handleFatalError(CODE_INVALID_HASHTABLE_SIZE);
    }
    hashTable = malloc(hashTableSize * sizeof(bucket));
    instruction *instructions;

    if (argc <=2) {
        nrOfInstructions = readInstructions(&instructions, "stdin", 1);
        for (j=0; j<nrOfInstructions; j++) {
            executeInstruction(instructions[j], &hashTable, &hashTableSize);
        }
    } else {
        for (i=2; i<argc; i++) {
            nrOfInstructions = readInstructions(&instructions, argv[i], 0);
            for (j=0; j<nrOfInstructions; j++) {
                executeInstruction(instructions[j], &hashTable, &hashTableSize);
            }
            free(instructions);
            instructions = NULL;
        }
    }

    i += 10;
    return 0;
}