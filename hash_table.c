#include "hash_table.h"
#include "log_service.h"

void executeInstruction(instruction inst, bucket*** hashTable, int size)
{
	printf("Executing : %s:\n", commandNames[inst.command]);
	if (inst.command == ADD) {
		addWord(hashTable, size, inst.arg1);
	} else if (inst.command == REMOVE) {
        removeWord(hashTable, size, inst.arg1);
    } else if (inst.command == FIND) {
		find(hashTable, size, inst.arg1, inst.arg2);
	} else if (inst.command == PRINT) {
		print(hashTable, size, inst.arg1);
	} else if (inst.command == BPRINT) {
        printBucket(hashTable, atoi(inst.arg1), inst.arg2);
    } else if (inst.command == CLEAR) {
        clearTable(hashTable, size);
	} else if (inst.command == RESIZE) {
		if (strcmp(inst.arg1, "double") == 0) {
			printf("TODO\n");
		} else {
			printf("TODO\n");
		}
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
    int fd = STDOUT_FILENO;
    if (file) {
        FILE *fd = fopen(file, "r");
    }

    char buffer[100];
    ssize_t written = 0;
    ssize_t toBeWritten = 0;
    bucket* puppet = (*hashTable)[bucketIndex];
    while (puppet != NULL) {
        toBeWritten = sprintf(buffer, "%s ", puppet->word);
        written = write(fd, buffer, strlen(buffer) + 1);
        puppet = puppet->next;
        if (written!= toBeWritten + 1) {
            printf("WARNING!! %d to %d\n", (int)toBeWritten, (int)written);
        }
    }
    write(fd, "\n", 1);
    if (file) {
        fclose(fd);
    }
}

void print(bucket*** hashTable, int size, char* file)
{
    int fd = STDOUT_FILENO, i;
    if (file) {
        FILE *fd = fopen(file, "r");
    }

    char buffer[100];
    ssize_t written = 0;
    ssize_t toBeWritten = 0;
    bucket* puppet;
    for (i=0; i<size; i++) {
        puppet = (*hashTable)[i];
        while (puppet != NULL) {
            toBeWritten = sprintf(buffer, "%s ", puppet->word);
            written = write(fd, buffer, strlen(buffer) + 1);
            puppet = puppet->next;
            if (written!= toBeWritten + 1) {
                printf("WARNING!! %d to %d\n", (int)toBeWritten, (int)written);
            }
        }
        write(fd, "\n", 1);
    }
    if (file) {
        fclose(fd);
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
            puppet->next->prev = puppet->prev;
            free(puppet);
            return;
        }
        puppet = puppet->next;
    }
}

void find(bucket*** hashTable, int size, char *word, char* file)
{
    int fd = STDOUT_FILENO;
    ssize_t written = 0;
    if (file) {
        FILE *fd = fopen(file, "r");
    }
    int hash = myHash(size);
    bucket *puppet = (*hashTable)[hash];

    while (puppet != NULL) {
        if (strcmp(puppet->word, word) == 0) {
            written = write(fd, "TRUE\n", 4);
            break;
        }
        puppet = puppet->next;
    }
    if (written <= 0) {
        written = write(fd, "FALSE\n", 5);
    }
    if (file) {
        fclose(fd);
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
            nextPuppet = puppet->next;
            free(puppet);
            puppet = puppet->next;
        }

    }
}

int myHash(int hashSize)
{
    srand((unsigned)time(NULL));
    return (rand() % hashSize);
      }
