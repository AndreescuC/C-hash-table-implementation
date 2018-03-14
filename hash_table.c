#include "hash_table.h"
#include "log_handler.h"

/**
 * Functie de hash bazata pe djb2 a lui Dan Bernstein
 * http://www.cse.yorku.ca/~oz/hash.html
 * @return valoarea de dispersie (cheia)
 */
unsigned int hash(const char *str, unsigned int hash_length)
{
	unsigned int hash = 5381;
	int c;

	while ((c = *str++) != 0)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash % hash_length);
}

void executeInstruction(instruction inst, bucket*** hashTable, unsigned int *size)
{
    unsigned int sizeByValue = *size;
	if (inst.command == ADD) {
		addWord(hashTable, sizeByValue, inst.arg1);
	} else if (inst.command == REMOVE) {
        removeWord(hashTable, sizeByValue, inst.arg1);
    } else if (inst.command == FIND) {
		find(hashTable, sizeByValue, inst.arg1, inst.arg2);
	} else if (inst.command == PRINT) {
		print(hashTable, sizeByValue, inst.arg1);
	} else if (inst.command == BPRINT) {
        printBucket(hashTable, inst.arg1, inst.arg2);
    } else if (inst.command == CLEAR) {
        *hashTable = clearTable(*hashTable, sizeByValue);
	} else if (inst.command == RESIZE) {
        *size = resize(hashTable, sizeByValue, inst.arg1);
	} else {
		handleFatalError(CODE_INVALID_INSTRUCTION);
	}
}

void addWord(bucket*** hashTable, unsigned int size, char *word)
{
	bucket* newElement;

    char *pos;
    if ((pos=strchr(word, '\r')) != NULL)
        *pos = '\0';
    if (strlen(word) < 1)
        handleFatalError(CODE_INVALID_ARGUMENT);

	int hashIndex = hash(word, size);
	bucket *puppet = (*hashTable)[hashIndex];
	
	if (puppet == NULL) {
        newElement = (bucket*)malloc(sizeof(bucket));
        strcpy(newElement->word, word);
        newElement->next = NULL;
		newElement->prev = NULL;
        (*hashTable)[hashIndex] = newElement;
		return;
	}

	while (puppet->next != NULL) {
        if (strcmp(puppet->word, word) == 0) {
            return;
        }
		puppet = puppet->next;
	}
    if (strcmp(puppet->word, word) == 0) {
        return;
    }
    newElement = (bucket*)malloc(sizeof(bucket));
    strcpy(newElement->word, word);
    newElement->next = NULL;
	newElement->prev = puppet;
	puppet->next = newElement;
}

void printBucket(bucket*** hashTable, char* bucketIndexString, char* file)
{
    int bucketIndex = atoi(bucketIndexString);
    if (bucketIndex == 0 &&
                (!isdigit(bucketIndexString[0]) || strlen(bucketIndexString) != 1)) {
        handleFatalError(CODE_INVALID_ARGUMENT);
    }
    bucket *puppet = (*hashTable)[bucketIndex];
    char *pos;
    if ((pos=strchr(file, '\r')) != NULL)
        *pos = '\0';

    if (strlen(file)) {
        FILE *fd = fopen(file, "a");
        if (puppet == NULL) {
            fclose(fd);
            return;
        }
        while (puppet != NULL) {
            if (puppet->prev != NULL) {
                fprintf(fd, " ");
            }
            fprintf(fd, "%s", puppet->word);
            puppet = puppet->next;
        }
        fprintf(fd, "\n");
        fclose(fd);
    } else {
        if (puppet == NULL) {
            return;
        }
        while (puppet != NULL) {
            if (puppet->prev != NULL) {
                printf(" ");
            }
            printf("%s", puppet->word);
            puppet = puppet->next;
        }
        printf("\n");
    }
}

void print(bucket*** hashTable, unsigned int size, char* file)
{
    int i;
    bucket* puppet;
    char *pos;
    if ((pos=strchr(file, '\r')) != NULL) {
        *pos = '\0';
    }
    if (strlen(file)) {
        FILE *fd = fopen(file, "a");
        for (i=0; i<size; i++) {
            puppet = (*hashTable)[i];
            if (puppet == NULL) {
                continue;
            }
            while (puppet != NULL) {
                if (puppet->prev != NULL) {
                    fprintf(fd, " ");
                }
                fprintf(fd, "%s", puppet->word);
                puppet = puppet->next;
            }
            fprintf(fd, "\n");
        }
        fclose(fd);
    } else {
        for (i=0; i<size; i++) {
            puppet = (*hashTable)[i];
            if (puppet == NULL) {
                continue;
            }

            while (puppet != NULL) {
                if (puppet->prev != NULL) {
                    printf(" ");
                }
                printf("%s", puppet->word);
                puppet = puppet->next;
            }
            printf("\n");
        }
    }
}

void removeWord(bucket*** hashTable, unsigned int size, char *word)
{
    char *pos;
    if ((pos=strchr(word, '\r')) != NULL)
        *pos = '\0';
    int hashIndex = hash(word, size);
    bucket *puppet = (*hashTable)[hashIndex];
    if (puppet == NULL) {
        return;
    }
    if (strcmp(puppet->word, word) == 0) {
        (*hashTable)[hashIndex] = puppet->next;
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

void find(bucket*** hashTable, unsigned int size, char *word, char* file)
{
    char *pos;
    if ((pos=strchr(word, '\r')) != NULL)
        *pos = '\0';
    if ((pos=strchr(file, '\r')) != NULL)
        *pos = '\0';
    int hashIndex = hash(word, size);
    bucket *puppet = (*hashTable)[hashIndex];
    while (puppet != NULL) {
        if (strcmp(puppet->word, word) == 0) {
            if (strlen(file)) {
                FILE *fd = fopen(file, "a");
                fprintf(fd, "True\n");
                fclose(fd);
            } else {
                printf("True\n");
            }
            return;
        }
        puppet = puppet->next;
    }
    if (strlen(file)) {
        FILE *fd = fopen(file, "a");
        fprintf(fd, "False\n");
        fclose(fd);
    } else {
        printf("False\n");
    }
}

bucket** clearTable(bucket** hashTable, unsigned int size)
{
    int i;
    bucket *puppet, *nextPuppet;
    for (i=0; i<size; i++) {
        puppet = hashTable[i];
        if (puppet == NULL) {
            continue;
        }
        nextPuppet = puppet->next;
        while (nextPuppet != NULL) {
            nextPuppet->prev = NULL;
            free(puppet);
            puppet = nextPuppet;
            nextPuppet = nextPuppet->next;
        }
        free(puppet);
        hashTable[i] = NULL;
    }
    return hashTable;
}

unsigned int resize(bucket*** hashTable, unsigned int size, char* type)
{
    char *pos;
    if ((pos=strchr(type, '\r')) != NULL)
        *pos = '\0';
    unsigned int newSize = 0, i;
    if (strcmp(type, "double") == 0){
        newSize = size * 2;
    } else if (strcmp(type, "halve") == 0) {
        newSize = size / 2;
    }
    if (newSize == 0) {
        handleFatalError(CODE_INVALID_ARGUMENT);
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
    *hashTable = clearTable(*hashTable, size);
    *hashTable = newHashTable;
    return newSize;
}
