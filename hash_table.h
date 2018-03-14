#include "struct.h"
#include "std.h"

#ifndef TEMA1_HASH_TABLE_H
#define TEMA1_HASH_TABLE_H

void addWord(bucket ***hashTable, unsigned int size, char *word);
void removeWord(bucket ***hashTable, unsigned int size, char *word);
void find(bucket*** hashTable, unsigned int size, char *word, char* file);
void print(bucket*** hashTable, unsigned int size, char* file);
void printBucket(bucket*** hashTable, int bucketIndex, char* file);
bucket** clearTable(bucket** hashTable, unsigned int size);
unsigned int resize(bucket*** hashTable, unsigned int size, char* type);
void executeInstruction(instruction inst, bucket ***hashTable, unsigned int *size);

#endif
