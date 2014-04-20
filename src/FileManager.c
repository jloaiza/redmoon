#include "FileManager.h"
#include <stdio.h>

FILE* file = 0;

int openFile(char* pFileDir){
	if (file == 0){
		file = fopen(pFileDir, "w");
		if (file == 0){
			printf("Error: No se ha podido abrir el archivo %s.\n", pFileDir);
			return 0;
		} else {
			return 1;
		}
	} else {
		printf("Error: Ya se han abierto el número máximo de archivos permitidos.\n");
		return 0;
	}
}

void closeFile(){
	if (file != 0){
		fclose(file);
	}
}

void writeToFile(char* pString){
	fprintf(file, "%s", pString);
}