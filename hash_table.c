
int myHash(char *word, int *size);
void add(bucket *hashTable, int *size, char *word);

void printHashTablee(bucket **hashTable, int size)
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

void executeInstruction(instruction inst, bucket ***hashTable, int size)
{
	
	printHashTablee(*hashTable, size);
	char buf[12];
	int i;
	for (i=0; i<2; i++) {
		printHashTablee(*hashTable, size);
		printf("Acii\n");
		bucket* newElement;
		newElement = (bucket*)malloc(sizeof(bucket));
		sprintf(buf, "src%d", i);
		strcpy(newElement->word, buf);
		newElement->next = NULL;
		printf("Ma uit pe poz %d\n", i % 5);
		bucket *puppet = *hashTable[i % 5];
		printf("Uite: %s\n", puppet->word);
		if (puppet->word == NULL) {
			printf("New element\n");
			newElement->prev = NULL;	
			*hashTable[i % 5] = newElement;
			continue;
		}
		while (puppet->next != NULL) {
			printf("Caut %s", puppet->word);
			puppet = puppet->next;
		}
		printf("\n");
		newElement->prev = puppet;
		puppet->next = newElement;

	}
	//return hTable;
	/*printf("%s:\n", commandNames[inst.command]);
	if (inst.command == ADD) {
		add(**hashTable, size, inst.arg1);
	} else if (inst.command == REMOVE) {
		printf("TODO\n");
	} else if (inst.command == FIND) {
		printf("TODO\n");
	} else if (inst.command == PRINT) {
		printf("TODO\n");
	} else if (inst.command == BPRINT) {
		printf("TODO\n");
	} else if (inst.command == RESIZE) {
		if (strcmp(inst.arg1, "double") == 0) {
			printf("TODO\n");
		} else {
			printf("TODO\n");
		}
	} else {
		handleFatalError(CODE_INVALID_INSTRUCTION, 0);
	}
	printf("Execute:");
	//printHashTable(*hashTable, *size);*/
}

void add(bucket *hashTable, int *size, char *word)
{
	bucket* newElement;
	newElement = (bucket*)malloc(sizeof(bucket));
	strcpy(newElement->word, word);
	newElement->next = NULL;
	bucket **hTable;
	printf("PE AICI\n");
	hTable = &hashTable;
	int hash = myHash(word, size);
	bucket *puppet = hTable[hash];
	
	if (puppet == NULL) {
		newElement->prev = NULL;	
		hTable[hash] = newElement;
		printf("Add:");
		return;
	}
	while (puppet->next != NULL) {
		puppet = puppet->next;
	}
	newElement->prev = puppet;
	puppet->next = newElement;
	printf("Add:");
}

int myHash(char *word, int *size)
{
	srand(time(NULL));
	return (rand() % *size);
}