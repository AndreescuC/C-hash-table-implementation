#include "std.h"

#ifndef TEMA1_STRUCT_H
#define TEMA1_STRUCT_H

static const char* commandNames[] = {"add", "remove", "find", "clear", "print", "bprint", "resize", "invalid" };

static const int CODE_INVALID_HASHTABLE_SIZE = 0;
static const int CODE_INVALID_FILENAME = 1;
static const int CODE_INVALID_INSTRUCTION = 2;
static const int CODE_INVALID_ARGUMENT = 3;

static const char MSG_INVALID_HASHTABLE_SIZE[] = "Invalid hash table size provided";
static const char MSG_INVALID_FILENAME[] = "Invalid input filename provided";
static const char MSG_INVALID_INSTRUCTION[] = "Invalid instruction provided";
static const char MSG_INVALID_ARGUMENT[] = "Invalid argument provided";

typedef struct bucket {
    char word[500];
    struct bucket *next;
    struct bucket *prev;
}bucket;

typedef enum command {ADD, REMOVE, FIND, CLEAR, PRINT, BPRINT, RESIZE, INVALID_COMMAND}command;

typedef struct instruction {
    enum command command;
    char arg1[100];
    char arg2[100];
}instruction;

instruction initializeInstruction();

#endif
