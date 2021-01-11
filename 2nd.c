#include "2nd.h"
#include "Header.h"
#include <cstddef>
int freqListToNodes(Table* linker, int strlen) {
	unsigned int freq = 1000;
	unsigned int freq2 = 1000, n;
	box pair;
	box pair2;
	box* pairmax;
	//sortbox()>;
	//po ubivaniu
	int len = strlen;
	box* slovarik = (box*)malloc(sizeof(box) * strlen);
	for (int i = 0; strlen != i; i++) {
		slovarik[i].data == linker[i].byteFromFile;
		slovarik[i].frequency = linker[i].freq;
		//goto further;
	}
	while (len != 0) {
		for (n = 0; n+1 != len; n++) { //  (n = 0; strlen != len; n++); len++
			pair = slovarik[n];
			freq = pair.frequency;
			pair2 = slovarik[n + 1];
			freq2 = pair2.frequency;
			//len++;
			//len++;
			if (freq < freq2) {
				slovarik[n] = pair2;
				slovarik [n + 1] = pair;
			}
		}
		len--;
	}
	len = strlen;
	int* mass = (int*)malloc(sizeof(int) * (n + 1)); // linker's mass of hunode's
	for (int i = 0; i != n + 2; i++) {
		hunode* node = (hunode*)malloc(sizeof(hunode));
		pair = slovarik[i];
		node->frequency = pair.frequency;//realloc()
		node->data = pair.data;
		node->L = NULL;
		node->R = NULL;
		*(mass + i * sizeof(int)) = node;
	}
	hunode** smallest = mass + n + 2; //i // linker on address for last element
	hunode* tmp;
	hunode* lownow, prevlow; // for loop, linkers
	lownow = *smallest;
	for (int i = len; i != 1; i--) { //search_koren' = comprasing
		hunode* node = (hunode*)malloc(sizeof(hunode));
		tmp = *(mass + i * sizeof(int)-1);
		//prevlow = *tmp;
		node->frequency = tmp->frequency+lownow->frequency;
		node->data = NULL;
		node->L = lownow;
		node->R = tmp;
		*(mass + i * sizeof(int)-1) = node;
		*(mass + i * sizeof(int)) = NULL;
		mass = hunSort(mass, i); 
		lownow = mass + i;
	}
	int* node = *(mass); //linker for koren'
	//free nodes//
	T_free(node);
//for (int i = len; i+1 != 0; i--) {
//	//free
//	long int 
//	(free(*(mass + i)) == 0) ? printf("finally got free one more value") : printf("not success");
//}

	free(mass);
	//char prefix[PREFLEN];
	for (int i = 0; i != n+1; i++) { //box_value = from ch to prefix
		pair = slovarik[i];
		*(pair.prefix) = T_Search(node, pair, 1); //! or one more value for swap
	}
	free_linker(); // delete box's
	linker = slovarik;
	return linker;
}
int hunSort(int* mass, int strlen) {
	box* pair;
	box* pair2;
	unsigned int freq;
	unsigned int freq2;
	while (strlen != 0) {
		for (int j = 0; strlen != j+1; j++) {
			pair = mass[j];
			freq = pair->frequency;
			pair2 = mass[j + 1];
			freq2 = pair2->frequency;
			//len++;
			//len++;
			if (freq < freq2) {
				mass[j] = pair2;
				mass[j + 1] = pair;
			}
		}
		strlen--;
	}
}
int T_Search(hunode* node, box s, int mode) {
	int tmp;
	static int i = 0;
	char prefix[PREFLEN];
	if (!node)
		tmp = 0;
	else if (node->data == s.data)
		tmp = 1;
	else if (node->frequency > s.frequency) {
		if (node->L == NULL)
			tmp = 0;
		else {
			prefix[i] = 0;
			i++;
			tmp = T_Search(node->L, s, prefix);
		}
	}
	else
		if (node->R == NULL)
			tmp = 0;
		else {
			prefix[i] = 1;
			i++;
			tmp = T_Search(node->R, s, prefix);
		}
	prefix[i] = '\0';
	if (mode != 0)
		return *(prefix); // ukazatel'
	else
		return tmp; // /* 0 or 1 */
}
//int T_Search_fromPref(hunode* node, char s[], int strlen) {
//	for (int i = 0; i != strlen; i++) {
//		if (node->data = s) {
//			s = node->data;
//			return s;
//		}
//		if (s[i] == 1) {
//			if (node->R != 0) {
//				node = node->R;
//			}
//			else printf("problems with finding char from prefix");
//		}
//		if (s[i] == 0) {
//			if (node->L != 0) {
//				node = node->L;
//			}
//			else printf("problems with finding char from prefix");
//		}
//	}
//	return s;
//}
hunode* T_free(hunode* node) {
	if (NULL != node->L)
		node->L = T_free(node->L);
	if (NULL != node->R)
		node->R = T_free(node->R);
	free(node);
	return NULL;
}


	//T_free(node);
//for (int i = n+2; prevlow.frequency != -1; i--) {
//	//lownow = smallest;
//		if (lownow < *(mass+i)) {
//			prevlow = *(lownow);
//			lownow = mass + i;
//		}
//	mass = perestanovka(mass);
//	i--;
//}
	////mass = perestanovka(mass); /// - if =0 delete or set -1 -> vse vlevo

	//hunode* smallest = node;//
//for (int i=0; *((mass+i)->frequency) < smallest.frequency; i++){//
//	while (lownow.freq!=1000)
//		*(lownow->frequency) = mass[i];
//	if ) {
//		
//	}
//}
//mass + n * (sizeof(hunode)) = NULL;
//8
	//mass = perestanovka(mass); /// - if =0 delete or set -1 -> vse vlevo
//	sortbox() {
//		if (freq < freq2) {
//			linker[n] = pair2;
//			linker[n + 1] = pair;
//		}
//	}
//

//hunode* T_Insert(hunode* node, int ins) {
//	if (NULL == node) {
//		hunode* node = (hunode*)malloc(sizeof(hunode));
//		node->data = ins;
//		node->R = node->L = NULL;
//		return node;
//	}
//	else if (ins == node->data) {
//		printf("1 element was duplicated.\n");
//		return node;
//	}
//	else if (ins < node->data) {
//		node->L = T_Insert(node->L, ins);
//	}
//		else node->R = T_Insert(node->R, ins);
//	return node;
//}
//	int T_Search(hunode * node, char s, int prefix) {
//		int tmp;
//		int* i = 0;
//		char s[128];
//		if (!node)
//			tmp = 0;
//		else if (node->data == s)
//			s[i] = '1';
//		else if (node->data > s)
//			if (node->L = NULL)
//				tmp = 0;
//		tmp = T_Search(node->L, s, prefix);
//			else
//				if (node->L = NULL)
//					tmp = 0;
//		tmp = T_Search(node->R, s, prefix);
//		if (prefix != 0) return prefix; /* 0 or 1 */
//		else return tmp;
//	}


		//void T_print(hunode * node, FILE * output) {
		//	if (node->L != NULL)
		//		T_print(node->L, output);
		//	fprintf(output, "%d \n", node->v);
		//	if (node->R != NULL)
		//		T_print(node->R, output);
		//}
///
///int T_Search(hunode* node, int s) {
///	int tmp;
///	if (!node)
///		tmp = 0;
///	else if (node->v == s)
///		tmp = 1;
///	else   if (node->v > s)
///		if (node->L = NULL)
///			tmp = 0;
///	tmp = T_Search(node->L, s);
///		else
///			if (node->L = NULL)
///				tmp = 0;
///	tmp = T_Search(node->R, s);
///	return tmp; /* 0 or 1 */
///}
///
