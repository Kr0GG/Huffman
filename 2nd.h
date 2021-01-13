#ifndef main_h_included
#define main_h_included
#define PREFLEN 256
#include "table.h"

typedef struct hunode {
    char data;
    unsigned int frequency;
    struct hunode* L,
        * R;
} hunode;
typedef struct box {
    char data;
    char prefix[PREFLEN];
    unsigned int frequency;
    //struct box* next;
} box;

//typedef struct ListItem {       
//    hunode* tekuwui;
//    ListItem* pNext;
//    ListItem* pPrev;
//}ListItem;
//typedef struct Table {
//    char byteFromFile;
//    //char prefix[PREFLEN];
//    unsigned int freq;
//}Table;
int freqListToNodes(Table* linker, int strlen);
//hunode* T_Insert(hunode* node, int ins);
int T_Search(hunode* node, box s, int mode);
//void T_print(hunode* node, FILE* output);
hunode* T_free(hunode* node);
hunode** hunSort(hunode** mass, int strlen);
void printmas(hunode** mass, int len);
int T_Search_fromPref(hunode* node, char s[], int strlen);
#endif