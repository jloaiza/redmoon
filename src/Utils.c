#include "Utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void concatenateStringToString(char* pBuffer, char* pString, int pCharCount){
	printf("concat: %d\n", pCharCount);
	int i;
	for (i = 0; i < pCharCount; i++){
		strcat(pBuffer, pString);
	}
}

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

char* fillStringWithSpace(char* pString, int pLength){
	int i = 0;
	char* name = malloc((pLength+1)*sizeof(char));
	if (pString != 0){
		for (;pString[i] != '\0'; i++){
			name[i] = pString[i];
		}
	}
	for (;i<pLength;i++){
		name[i] = ' ';
	}
	name[pLength] = '\0';
	return name;
}

int intLength(int pInt){
	int i = 1;
	while (pInt/pow(10, i) != 0){
		pInt = pInt/pow(10, i);
		i++;
	}
	return i;
}

char* intToString(int pInt){

	int power = intLength(pInt);
	char* string = (char*)malloc((power+1)*sizeof(char));
	string[0] = '\0';

	while (power > 0){
		char* charVal = (char*)malloc(2*sizeof(char));

		charVal[0] = '0' + (pInt%(int)pow(10, power))/pow(10, power-1);
		charVal[1] = '\0';

		strcat(string, charVal);
		power--;
		free(charVal);
	}
	return string;
}