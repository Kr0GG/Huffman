#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ERROR_OPEN_FILE -3

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "coder.h"
struct Table {
    char byteFromFile;
    int freq;
};
struct Table* analysFileByts(FILE*, unsigned long*);
void analysByte(char, struct Table**);
