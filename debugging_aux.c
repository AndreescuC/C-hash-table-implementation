#include "debugging_aux.h"

void printInstructions(instruction *head, int n)
{
	int i;
	printf("\n*************************PRINTING INSTRUCTIONS*************************\n");
	for (i=0; i<n; i++) {
		printf("%s-%s-%s\n", commandNames[head[i].command], head[i].arg1, head[i].arg2);
	}
	printf("*************************PRINTING INSTRUCTIONS*************************\n\n");
}

void printHashTable(bucket **hashTable, unsigned int size)
{
	int i, count;
	bucket *puppet;
	printf("*************************PRINTING HASHTABLE*************************\n");
	for (i=0; i<size; i++) {
		count = 0;
		puppet = hashTable[i];
		while (puppet != NULL) {
			count ++;
			printf("%s -> ", puppet->word);
			puppet = puppet->next;
		}
		printf(" [%d elements]\n", count);
	}
	printf("*************************PRINTING HASHTABLE*************************\n");
}