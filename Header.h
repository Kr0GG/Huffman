#ifndef main1_h_included
#define main1_h_included
#define _CRT_SECURE_NO_WARNINGS
#define ERROR_OPEN_FILE -3
#include "2nd.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "coder.h"
#include "table.h"
struct Table* analysFileByts(FILE*, unsigned long*);
void analysByte(char inputByte, struct Table** table, unsigned long* lenght_table);
void write_decoded_file(FILE* Input_file, box* slov, unsigned long lenght);
void write_coded_file( FILE* inputFile, unsigned long n, struct Table** , box* slovarik);
#endif