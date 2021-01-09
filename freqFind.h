#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const unsigned int MAX_LENGTH = 1 * 1024 * 1024;
const unsigned int CHUNK_SIZE = 128;

struct Table {
    char byteFromFile;
    char prefix;
    unsigned int freq;
};
struct Table* analysFileByts(FILE*, unsigned long*);
void analysByte(char, struct Table**);