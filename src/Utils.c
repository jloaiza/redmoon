#include "Utils.h"

int strcomp(char* pStr1, char* pStr2){
	int i;
	for (i = 0;;i++){
		if (pStr1[i] == '\0' && pStr2[i] == '\0'){
			return 0;
		} else if ((pStr1[i] == '\0' && pStr2[i] != '\0') || pStr1[i] < pStr2[i]){
			return -1;
		} else if ((pStr1[i] != '\0' && pStr2[i] == '\0') || pStr1[i] > pStr2[i]){
			return 1;
		}
	}
}
