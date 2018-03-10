#include "struct.h"
#include "std.h"

#ifndef TEMA1_HASH_TABLE_H
#define TEMA1_HASH_TABLE_H

int myHash(int size);
void addWord(bucket ***hashTable, int size, char *word);
void removeWord(bucket ***hashTable, int size, char *word);
void find(bucket*** hashTable, int size, char *word, char* file);
void print(bucket*** hashTable, int size, char* file);
void printBucket(bucket*** hashTable, int bucketIndex, char* file);
void clearTable(bucket*** hashTable, int size);
void executeInstruction(instruction inst, bucket ***hashTable, int size);

#endif
