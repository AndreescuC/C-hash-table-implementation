void printHashTable(bucket **hashTable, int size);

void printInstructions(instruction *head, int n)
{
	int i;
	printf("\n*************************PRINTING INSTRUCTIONS*************************\n");
	for (i=0; i<n; i++) {
		printf("%s-%s-%s\n", commandNames[head[i].command], head[i].arg1, head[i].arg2);
	}
	printf("*************************PRINTING INSTRUCTIONS*************************\n\n");
}

void printHashTable(bucket **hashTable, int size)
{
	int i;
	bucket *puppet;
	printf("\n*************************PRINTING HASHTABLE*************************\n");
	for (i=0; i<size; i++) {
		puppet = hashTable[i];
		while (puppet != NULL) {
			printf("%s -> ", puppet->word);
			puppet = puppet->next;
		}
		printf("\n");
	}
	printf("*************************PRINTING HASHTABLE*************************\n\n");
}