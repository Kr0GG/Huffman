#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define uint unsigned int
#define PREFLEN 256
typedef struct box {
    char data;
    char prefix[PREFLEN];
    unsigned int frequency;
    //struct box* next;
} box;
unsigned int coder(char byte_from_file, char** file_byts, int end, box* slovarik, unsigned long slov_len);
int decoder(char byte_from_c_file, char* finded_byte, box* slovarik, unsigned long slov_len);
