#include "Header.h";

int main() {
    FILE* file;
    unsigned long n;
    char command;

    file = fopen("f.txt", "rb");
    if (file == NULL) {
        printf("hhhhh");
    }
    do {
        printf("0- code, 1 - decode");
        command = getch();
        if (command == 0) {
            file = open_file("f.txt", "rb");
            if (file == NULL) {
                printf("Programm can't open File");
                getch();
            }
            code_logic(file);
            
        }
        else {
            file = open_file("f.txt", "rb");
            if (file == NULL) {
                printf("Programm can't open File");
                getch();
            }
            decode_logic(file);

        }
    } while (1);
    file = fopen("f.txt", "rb");
    if (file == NULL) {
        printf("hhhhh");
    }
    else {
        struct Table* table = analysFileByts(file, &n);
    }

}
FILE* open_file(char* name, char* mode) {
    FILE* file = fopen(name, mode);
}
void code_logic(FILE* inputFile) {
    struct Table* table;
    unsigned long n;
    table = analysFileByts(inputFile, &n);
    //Ваня создает дерево
    write_coded_file(inputFile, n, &table);
    free(table);
    fclose(inputFile);
    printf("ok ok ok");
}
void decode_logic(FILE* inputFile) {
    struct Table* table;
    unsigned long n;
    table = read_table_of_coded_file(inputFile, &n);
    //Ваня создает дерево
    write_decoded_file(inputFile);
    free(table);
    fclose(inputFile);
    printf("ok ok ok");
}
