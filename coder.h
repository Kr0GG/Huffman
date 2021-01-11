#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define uint unsigned int

unsigned int coder(char byte_from_file, char** file_byts, int end, struct slovarik* slovarik, unsigned long slov_len);
int decoder(char byte_from_c_file, char* finded_byte, struct slovarik* slovarik, unsigned long slov_len);