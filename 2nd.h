#ifndef main_h_included
#define main_h_included
#define PREFLEN 256
typedef struct hunode {
    char data;
    unsigned int frequency;
    struct hunode* L,
        * R;
} hunode;
//typedef struct ListItem {       
//    hunode* tekuwui;
//    ListItem* pNext;
//    ListItem* pPrev;
//}ListItem;
typedef struct box {
    char data;
    char prefix[PREFLEN];
    unsigned int frequency;
    //struct box* next;
} box;
//typedef struct Table {
//    char byteFromFile;
//    //char prefix[PREFLEN];
//    unsigned int freq;
//}Table;
int freqListToNodes(int* linker, int strlen);
hunode* T_Insert(hunode* node, int ins);
int T_Search(hunode* node, box s, int mode);
//void T_print(hunode* node, FILE* output);
hunode* T_free(hunode* node);
int hunSort(int* mass, int strlen);
#endif