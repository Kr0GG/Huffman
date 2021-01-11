#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ERROR_OPEN_FILE -3

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "coder.h"
struct Table {
    char byteFromFile;
    //char prefix[PREFLEN];
    int freq;
};
struct Table* analysFileByts(FILE*, unsigned long*);
void analysByte(char, struct Table**);
void write_decoded_file(FILE* Input_file, box* slov, unsigned long lenght);
void write_coded_file( FILE* inputFile, unsigned long n, struct Table** , box* slovarik);