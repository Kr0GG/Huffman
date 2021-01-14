#include "2nd.h"
#include "Header.h"
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
		slovarik[i].data = linker[i].byteFromFile;
		slovarik[i].frequency = linker[i].freq;
	}

	while (len != 0) {
		for (n = 0; n + 1 != len; n++) { 
			pair = slovarik[n];
			freq = pair.frequency;
			pair2 = slovarik[n + 1];
			freq2 = pair2.frequency;
			if (freq < freq2) {
				slovarik[n] = pair2;
				slovarik[n + 1] = pair;
			}
		}
		len--;
	}
	len = strlen;
	hunode** mass = (hunode**)malloc(sizeof(hunode*) * (strlen)); // linker's mass of hunode's
	for (int i = 0; i != len+1; i++) {
		hunode* node = (hunode*)malloc(sizeof(hunode));
		pair = slovarik[i];
		node->frequency = pair.frequency;
		node->data = pair.data;
		node->L = NULL;
		node->R = NULL;
		mass[i] = node;
	}
	hunode* smallest = mass[len-1]; //i // linker on address for last element
	hunode* tmp;
	hunode* lownow, prevlow; // for loop, linkers
	lownow = smallest;
	for (int i = len; i != 1; i--) { //search_koren' = comprasing
		hunode* node = (hunode*)malloc(sizeof(hunode));
		tmp = mass[i- 2];
		//prevlow = *tmp;
		node->frequency = tmp->frequency+lownow->frequency;
		node->data = NULL;
		node->L = lownow;
		node->R = tmp;
		mass[i - 2]= node;
		mass[i-1] = NULL;
		//printmas(mass, i-1);
		mass = hunSort(mass, i);
		lownow = mass[i-2];
	}
		char prefix[PREFLEN];
		doPref(mass[0], prefix, 0, slovarik);
	//free nodes//
	T_free(mass[0]);
	for (int i = 1; i < strlen+1; i++)
		free(mass[i]);
	//free(mass);????
	
	//free_linker(); // delete box's
	//linker = slovarik;
	return slovarik;
}
//char* T_Search(hunode* node, box s, int mode, char* prefix) {
//	int tmp = 0;
//	static int i = 0;
//	//char prefix[PREFLEN];
//	if (!node) {
//		tmp = 0;
//		return tmp;
//	}
//	else if (node->data == s.data) {
//		tmp = 1;
//		prefix[i] = '\0';
//	}
//	else if (node->L != NULL) {
//		if (node->L->frequency <= s.frequency) {
//			//while (node->L!=0)
//				//if (node->L->data != s.data)
//			for (hunode* node_tmp = node; node_tmp->L != 0; node_tmp = node_tmp->L){
//				char* prefix_tmp[PREFLEN];
//				if (T_Search(node_tmp->L, s, 1, prefix_tmp) != 1)
//					goto R;
//			}
//			//if (node->L == NULL)
//			//	tmp = 0; else {		
//			prefix[i] = '0';
//			i++;
//			tmp = T_Search(node->L, s, 1, prefix);
//		}
//		else goto R;
//	}
//	else
//R:		if (node->R == NULL)
//			tmp = 0;
//		else {
//			prefix[i] = '1';
//			i++;
//			tmp = T_Search(node->R, s, 1, prefix);
//		}
//	i = 0;//if (mode != 0)
//	return tmp; // /* 0 or 1 */
//}

void doPref(hunode* node, char arr[], int top, box* slovarik) {
	if (node->L) {
		arr[top] = '0';
		doPref(node->L, arr, top + 1, slovarik);
	}
	if (node->R) {
		arr[top] = '1';
		doPref(node->R, arr, top + 1, slovarik);
	}
	if (!(node->L) && !(node->R)) { //IsLeaf
		arr[top+1] = '\0';
		for (int j = 0; j != strlen; j++) //??
			if (node->data == slovarik[j].data) {
				for (int i = 0; i < top+1; i++)
					slovarik[j].prefix[i] = arr[i];
				break;//j = strlen;
				//j--;
			}
	}

}
hunode** hunSort(hunode** mass, int strlen) {
	hunode* pr1;
	hunode* pr2;
	unsigned int frq;
	unsigned int frq2;
	while (strlen != 0) {
		for (int j = 0; strlen != j + 1; j++) {
			//printmas(mass, strlen);
			pr1 = mass[j];
			frq = pr1->frequency;
			pr2 = mass[j + 1];
			if (pr2 == NULL) continue;
			frq2 = pr2->frequency;
			//len++;
			//len++;
			if (frq < frq2) {
				mass[j] = pr2;
				mass[j + 1] = pr1;
			}
		}
		strlen--;
		//printmas(mass, strlen);
		return mass;
	}
}
void printmas(hunode** mass, int len) { //for debug
	for (len; len != 0; len--) {
		if (NULL != mass[len - 1]) {
			printf("\n %d data \n", mass[len - 1]->frequency);
			printf("\n %d data \n", mass[len - 1]->data);
			//printf("\n %d data \n", mass[len - 1]->prefix);
		}
	}
	printf("konec\n");
}

int T_Search_fromPref(hunode* node, char s[], int strlen) {
	for (int i = 0; i != strlen; i++) {
		if (node->data = s) {
			s = node->data;
			return s;
		}
		if (s[i] == 1) {
			if (node->R != 0) {
				node = node->R;
			}
			else printf("problems with finding char from prefix");
		}
		if (s[i] == 0) {
			if (node->L != 0) {
				node = node->L;
			}
			else printf("problems with finding char from prefix");
		}
	}
	return s;
}
hunode* T_free(hunode* node) {
	if (NULL != node->L)
		node->L = T_free(node->L);
	if (NULL != node->R)
		node->R = T_free(node->R);
	free(node);
	return NULL;
}

