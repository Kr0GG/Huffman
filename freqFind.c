#include "Header.h"
#include "2nd.h"

const unsigned int MAX_LENGTH = 1 * 1024 * 1024;
const unsigned int CHUNK_SIZE = 128;

/*struct Table{
    char byteFromFile;
    int freq;
};*/

struct Table* analysFileByts(FILE* F, unsigned long* n) {
    struct Table* table = NULL;
    char buf;
    int counter = 0;
    while (fread(&buf, sizeof(char), 1, F) == 1) {
        analysByte(buf, &table, n);
        counter++;
    }
    if (feof(F)) {
        return table;
    }
    else printf("File read error.");
}
// ------TODO  предусмотреть получение события о конце файла 
void analysByte(char inputByte, struct Table** table, unsigned long* lenght_table) {
    static unsigned int len = 128, endTable = 0;
    static int init = 0;
    static struct Table* box;

    if (init == 0) {
        box = (struct Table*)malloc(sizeof(struct Table) * len);
        *table = box;// указатель на таблицу в другой функции
        init = 1;
    }

    for (unsigned int i = 0; i < endTable; i++) {
        if (inputByte == box[i].byteFromFile) {
            box[i].freq++;
            goto further;
        }
    }
    if (len > MAX_LENGTH) {
        free(box);
        //err(EXIT_FAILURE, "Слишком много входных данных!\n");
    }
    if (endTable >= len) {//??????
        len += 128;
        box = (struct Table*)realloc(box, sizeof(struct Table) * len);
        *table = box;// указатель на таблицу в другой функции
    }
    box[endTable].byteFromFile = inputByte;
    box[endTable].freq = 1;
    endTable++;
    *lenght_table = endTable;
further:;
}
struct Table* read_table_of_coded_file(FILE* Coded_file, unsigned long* n) {
    unsigned long len_table;
    struct Table* table;
    fread(&len_table, sizeof(unsigned long), 1, Coded_file);
    table = (struct Table*)malloc(sizeof(struct Table) * len_table);
    if (fread(table, sizeof(struct Table), len_table, Coded_file) != len_table) {
        printf("Error reading table");
        getch();
        //exit(ERROR_FILE_OPEN);
    }
    return table;
}
void write_coded_file(FILE* Original_file, unsigned long lenght_table, struct Table** table, box* slovarik) {
    FILE* output = NULL;
    char buf;
    char* coded_byts = NULL;
    unsigned int count_byts = 0;

    output = fopen("output.bin", "wb");
    if (output == NULL) {
        printf("Error opening file");
        getch();
        //exit(ERROR_FILE_OPEN);
    }

    fwrite(&lenght_table, sizeof(unsigned long), 1, output);
    if (fwrite(*table, sizeof(struct Table), lenght_table, output) != lenght_table) {
        printf("Error writing file");
        getch();
        //exit(ERROR_FILE_OPEN);
    }
    rewind(Original_file);
    while (fread(&buf, sizeof(char), 1, Original_file) == 1) {
        count_byts = coder(buf, &coded_byts, 0, slovarik, lenght_table);
    }
    if (feof(Original_file)) {
        count_byts = coder(buf, &coded_byts, 1, slovarik , lenght_table);
    }
    else {
        printf("Error reading file wcf");
        getch();
    }
    if (fwrite(coded_byts, sizeof(char), count_byts, output) != count_byts) {
        printf("Error writing file");
        getch();
    }
    else {
        printf("secsess!!!");
        getch();
    }


    fclose(output);
}
void write_decoded_file(FILE* Input_file , struct slovarik* slovarik,unsigned long lenght_table/*, указатель на начало данных в закодированном файле*/) {
    FILE* output = NULL;
    char buf;
    char bytesDecodedFieBuf[8];
    int count = 0;
    output = fopen("output.bin", "wb");
    if (output == NULL) {
        printf("Error opening file");
        getch();
        //exit(ERROR_FILE_OPEN);
    }

    while (fread(&buf, sizeof(char), 1, Input_file) == 1) {
        if (count = decoder(buf, bytesDecodedFieBuf, slovarik, lenght_table) != 0) {
            fwrite(bytesDecodedFieBuf, sizeof(char), count, output);
        }
    }
    if (feof(Input_file)) {
        printf("ok");
        getch();
    }
    else {
        printf("Error wd file");
        getch();
    }
}
