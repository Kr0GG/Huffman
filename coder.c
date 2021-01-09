#include "coder.h"

unsigned int coder(char byte_from_file, char** file_byts, int end) {//�������� ���� �� ����� � ��������� ����� (>0).
	const unsigned int MAX_LENGTH = 1 * 1024 * 1024;
	const unsigned int CHUNK_SIZE = 128;

	static unsigned int len = 128, buf_pos = 0;
	static char* buf; //������ ������ ������ �� �����
	static int init = 0;
	static char tmp[8];//������� 
	static int c = 0;

	char tmp_buf;//���� ���� ��������
	char* pref_str; //������ ��������
	char str_byte_tmp[9];
	size_t  str_len;
	unsigned int str_pos = 0;

	if (init == 0) {
		buf = (char*)malloc(sizeof(char*) * len);
		//*table = box;// ��������� �� ������� � ������ �������
		init = 1;
	}

	if (end > 0) {
		if ((strlen(tmp)) != 0) {
			char* nuls = "00000000";
			strlcat(tmp, nuls, 8 - c);//�������� 8- ����� ������ ������2������ tmp ������ �� 8 ���� � �������� � buf
			tmp_buf = toDec(tmp);
			buf[buf_pos] = tmp_buf;
			buf_pos++;
		}
		*file_byts = buf;
		return buf_pos;
	}

	if (buf_pos + 20 >= len) {//�����
		len += CHUNK_SIZE;
		buf = (char*)realloc(buf, sizeof(char*) * len);
		//*table = box;// ��������� �� ������� � ������ �������
	}
	//�������� ������ ��������
	pref_str = strcat(tmp, pref_str);
	str_len = strlen(pref_str);
	memset(tmp, '\0', 8);

	while ((str_len - str_pos) >= 8) {//  ������������� �������
		strlcpy(str_byte_tmp, pref_str + str_pos, 9); //8 c������� � ���������� "\0" � ����� ������
		//tmp_buf = str...(�� str_pos, �� str_pos + 8??? -1 ) �������� ���� � �������� ��� � �����
		tmp_buf = toDec(str_byte_tmp);
		buf[buf_pos] = tmp_buf;
		buf_pos++;
		str_pos += 8;
	}
	if ((str_len - str_pos) != 0) {
		int c = strlcpy(tmp, pref_str + str_pos, 8);// �� 8 ��������???????
		//tmp = str...(�� str_pos, �� (str_len - str_pos) - 1)
		/*if (end > 0) {
			char* nuls = "00000000";
			strlcat(tmp, nuls, 8-c);//�������� 8- ����� ������ �������
			//��������� tmp ������ �� 8 ���� � �������� � buf
			buf[buf_pos] = tmp_buf;
		}*/
	}
	/*else {
		//tmp = "";
		memset(tmp, '\0', 8);

	}*/
	/*if (len > MAX_LENGTH) {
		free(buf);
		//err(EXIT_FAILURE, "������� ����� ������� ������!\n");
	}*/
	return buf_pos;
}

char getNextBit(byte_from_c_file) { // ���������� ��������������� ��� 
	static char mask = 1;
	static int counter = 0;
	char newBit = 0;
	newBit = byte_from_c_file & mask;
	mask << 1;
	counter++;
	if (counter == 8) {
		mask = 1;
		counter = 0;
	}
}

void addBitToPreString(char* prefString, char bit) {
	int endStr = sizeof(prefString);
	if (bit == 0) {
		prefString[endStr] = "0";
		prefString[endStr+1] = "\0";
	}
	else {
		prefString[endStr] = "1";
		prefString[endStr + 1] = "\0";
	}
}

int decoder(char byte_from_c_file, char* finded_bytes) {//���������� ���� � ����� �����?????
	static char pref_string [256];
	static int init = 0;
	//char finded_byts[8];//???????????
	int ptr_finded_byts = 0;
	char byte_by_prefix;
	
	if (init == 0) {
		memset(pref_string, '\0', 256);//��������� ������ 
	}
 
	for (int i = 0; i < 8; i++) {
		char newBit = getNextBit(byte_from_c_file);
		addBitToPreString(pref_string, newBit);
		//pref_string[ptr_pref_string] = "";
		
		// �������� ��� � ������ ��������
		if (/* ������� ������*/) {
			memset(pref_string, '\0', 256);//��������� ������ 
			finded_bytes[ptr_finded_byts] = byte_by_prefix;
			ptr_finded_byts++;
		}
	}
	//*finded_byte = finded_byts;//??????????
	return ptr_finded_byts;
}
char toDec(char* bin) { //char_bin_to_int
	int tmp;
	char x = 0;
	uint size = strlen(bin);
	int j = size - 1;
	for (int i = 0; i < size; i++) {
		//        printf("%c %d\n",bin[i],i);
		if (bin[i] == '1') {
			tmp = 1 << j;
			x += tmp;
		}
		j--;
	}
	return x;
}