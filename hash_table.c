#include "hash_table.h"
#include "log_service.h"

void executeInstruction(instruction inst, bucket*** hashTable, int *size)
{
    int sizeByValue = *size;
	if (inst.command == ADD) {
		addWord(hashTable, sizeByValue, inst.arg1);
	} else if (inst.command == REMOVE) {
        removeWord(hashTable, sizeByValue, inst.arg1);
    } else if (inst.command == FIND) {
		find(hashTable, sizeByValue, inst.arg1, inst.arg2);
	} else if (inst.command == PRINT) {
		print(hashTable, sizeByValue, inst.arg1);
	} else if (inst.command == BPRINT) {
        printBucket(hashTable, atoi(inst.arg1), inst.arg2);
    } else if (inst.command == CLEAR) {
        clearTable(hashTable, sizeByValue);
	} else if (inst.command == RESIZE) {
        *size = resize(hashTable, sizeByValue, inst.arg1);
	} else {
		handleFatalError(CODE_INVALID_INSTRUCTION, 0);
	}
}

void addWord(bucket*** hashTable, int size, char *word)
{
	bucket* newElement;
	newElement = (bucket*)malloc(sizeof(bucket));
	strcpy(newElement->word, word);
	newElement->next = NULL;
	int hash = myHash(size);
	bucket *puppet = (*hashTable)[hash];
	
	if (puppet == NULL) {
		newElement->prev = NULL;	
        (*hashTable)[hash] = newElement;
		return;
	}

	while (puppet->next != NULL) {
		puppet = puppet->next;
	}
	newElement->prev = puppet;
	puppet->next = newElement;
}

void printBucket(bucket*** hashTable, int bucketIndex, char* file)
{
    bucket *puppet = (*hashTable)[bucketIndex];
    FILE *fd = fopen(file, "a+");

    if ( file && fd) {
        while (puppet != NULL) {
            fprintf(fd, "%s ", puppet->word);
            puppet = puppet->next;
        }
        fprintf(fd, "\n");
        fclose(fd);
    } else {
        while (puppet != NULL) {
            printf("%s ", puppet->word);
            puppet = puppet->next;
        }
        printf("\n");
    }
}

void print(bucket*** hashTable, int size, char* file)
{
    int i;
    bucket* puppet;
    FILE *fd = fopen(file, "a+");
    if (file && fd) {
        for (i=0; i<size; i++) {
            puppet = (*hashTable)[i];
            while (puppet != NULL) {
                fprintf(fd, "%s ", puppet->word);
                puppet = puppet->next;
            }
            fprintf(fd, "\n");
        }
        fclose(fd);
    } else {
        for (i=0; i<size; i++) {
            puppet = (*hashTable)[i];
            while (puppet != NULL) {
                printf("%s ", puppet->word);
                puppet = puppet->next;
            }
            printf("\n");
        }
    }
}

void removeWord(bucket*** hashTable, int size, char *word)
{
    int hash = myHash(size);
    bucket *puppet = (*hashTable)[hash];

    if (strcmp(puppet->word, word) == 0) {
        (*hashTable)[hash] = puppet->next;
        free(puppet);
        return;
    }
    puppet = puppet->next;
    while (puppet != NULL) {
        if (strcmp(puppet->word, word) == 0) {
            puppet->prev->next = puppet->next;
            if (puppet->next) {
                puppet->next->prev = puppet->prev;
            }
            free(puppet);
            return;
        }
        puppet = puppet->next;
    }
}

void find(bucket*** hashTable, int size, char *word, char* file)
{
    int hash = myHash(size);
    bucket *puppet = (*hashTable)[hash];

    while (puppet != NULL) {
        if (strcmp(puppet->word, word) == 0) {
            FILE *fd = fopen(file, "a+");
            if (file && fd) {
                fprintf(fd, "TRUE\n");
                fclose(fd);
            } else {
                printf("TRUE\n");
            }
            return;
        }
        puppet = puppet->next;
    }
    if (file) {
        FILE *fd = fopen(file, "a+");
        fprintf(fd, "FALSE\n");
        fclose(fd);
    } else {
        printf("FALSE\n");
    }
}

void clearTable(bucket*** hashTable, int size)
{
    int i;
    bucket* puppet, *nextPuppet;
    for (i=0; i<size; i++) {
        puppet = (*hashTable)[i];
        if (puppet == NULL) {
            continue;
        }
        nextPuppet = puppet->next;
        while (nextPuppet != NULL) {
            free(puppet);
            puppet = nextPuppet;
            nextPuppet = nextPuppet->next;
        }
        free(puppet);
    }
}

int resize(bucket*** hashTable, int size, char* type)
{
    int newSize = -1, i;
    if (strcmp(type, "double") == 0 || strcmp(type, "double\r") == 0){
        newSize = size * 2;
    } else if (strcmp(type, "halve") == 0 || strcmp(type, "halve\r") == 0) {
        newSize = size / 2;
    }
    if (newSize < 1) {
        handleFatalError(CODE_INVALID_ARGUMENT, -1);
    }
    bucket* puppet;
    bucket **newHashTable;
    newHashTable = malloc(newSize * sizeof(bucket));
    for (i=0; i<size; i++) {
        puppet = (*hashTable)[i];
        while (puppet != NULL) {
            addWord(&newHashTable, newSize, puppet->word);
            puppet = puppet->next;
        }
    }
    clearTable(hashTable, size);
    *hashTable = newHashTable;
    return newSize;
}

int myHash(int hashSize)
{
    return 1;
    srand((unsigned)time(NULL));
    return (rand() % hashSize);
      }
