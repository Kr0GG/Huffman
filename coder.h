#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define uint unsigned int

unsigned int coder(char byte_from_file, char** file_byts, int end);
int decoder(char byte_from_c_file, char** finded_byte);