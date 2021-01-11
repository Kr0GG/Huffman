#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define PREFLEN 256 //1 1 0 0 1 0 1 0 1 0 // 2^8

const unsigned int MAX_LENGTH = 1 * 1024 * 1024;
const unsigned int CHUNK_SIZE = 128;

struct Table {
    char byteFromFile;
    //char prefix[PREFLEN];
    unsigned int freq;
};
struct Table* analysFileByts(FILE*, unsigned long*);
void analysByte(char, struct Table**);
void write_decoded_file(FILE*);
void write_coded_file(FILE* Original_file, unsigned long lenght_table, struct Table** table, struct slovarik slovarik);
struct Table* read_table_of_coded_file(FILE* Coded_file, unsigned long* n);