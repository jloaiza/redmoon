#include "SymbolTable.h"
#include "Utils.h"
#include "FileManager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#define ID_LENGTH 31
#define LINE_LENGTH 5
#define PARAM_LENGTH 11
#define IS_USED_LENGTH 11
#define SPACE_LENGTH 1
#define TABLE_LINE_LENGTH 1 + SPACE_LENGTH + ID_LENGTH + SPACE_LENGTH + 1 + LINE_LENGTH + SPACE_LENGTH + 1 + PARAM_LENGTH + SPACE_LENGTH + 1 + ID_LENGTH + SPACE_LENGTH + 1 + IS_USED_LENGTH + SPACE_LENGTH + 3
#define FUNCTION_LINE_LENGTH 1 + SPACE_LENGTH + ID_LENGTH + SPACE_LENGTH + 1 + LINE_LENGTH + SPACE_LENGTH + 1 + ID_LENGTH + SPACE_LENGTH + 1 + IS_USED_LENGTH + SPACE_LENGTH + 3
#define TAG_LINE_LENGTH 1 + SPACE_LENGTH + ID_LENGTH + SPACE_LENGTH + 1 + LINE_LENGTH + SPACE_LENGTH + 1 + IS_USED_LENGTH + SPACE_LENGTH + 3
#define TABLE_EXTRALINES 13

const int NUMBER = 0;
const int VARIABLE = 1;
const int TAG = 2;
const int FUNCTION = 3;

char* getFinalLine();
void saveTableAux(char** pVariables, char** pFunctions, char** pTags, int pVarCount, int pFunctCount, int pTagsCount);
void produceVariableLine(char* pBuffer, char* pName, char* pLine, char* pParam, char* pFunction, char* pIsUsed);
void produceFunctionLine(char* pBuffer, char* pName, char* pLine, char* pParam, char* pIsUsed);
void produceTagLine(char* pBuffer, char* pName, char* pLine, char* pIsUsed);
void produceBasicLine(char* pBuffer, char* pName, char* pLine);
char* produceTitle(char* pTitle, int pTitleLenght);
char* produceVarDescription();
char* produceFunDescription();
char* produceTagDescription();

char* produceTagDescription(){
	char* tableLine = (char*)malloc((TABLE_LINE_LENGTH+3)*sizeof(char));
	char* space = fillStringWithSpace("", SPACE_LENGTH);

	strcat(tableLine, "*");
	strcat(tableLine, space);
	strcat(tableLine, fillStringWithSpace("Nombre", ID_LENGTH));

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "Linea");

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "¿Utilizada?");

	int i;
	for (i=TAG_LINE_LENGTH; i < TABLE_LINE_LENGTH;i++){
		strcat(tableLine, " ");
	}

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "\n");

	return tableLine;
}

char* produceFunDescription(){
	char* tableLine = (char*)malloc((TABLE_LINE_LENGTH+3)*sizeof(char));
	char* space = fillStringWithSpace("", SPACE_LENGTH);
	tableLine[0] = '\0';

	strcat(tableLine, "*");
	strcat(tableLine, space);
	strcat(tableLine, fillStringWithSpace("Nombre", ID_LENGTH));

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "Linea");

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, fillStringWithSpace("Parámetro", ID_LENGTH+1));

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "¿Utilizada?");

	int i;
	for (i=FUNCTION_LINE_LENGTH; i < TABLE_LINE_LENGTH;i++){
		strcat(tableLine, " ");
	}

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "\n");
	return tableLine;

}

char* produceVarDescription(){
	char* tableLine = (char*)malloc((TABLE_LINE_LENGTH+6)*sizeof(char));
	char* space = fillStringWithSpace("", SPACE_LENGTH);
	tableLine[0] = '\0';

	strcat(tableLine, "*");
	strcat(tableLine, space);
	strcat(tableLine, fillStringWithSpace("Nombre", ID_LENGTH));

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "Linea");

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "¿Parámetro?");

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, fillStringWithSpace("Función", ID_LENGTH+1));

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "¿Utilizada?");

	strcat(tableLine, space);
	strcat(tableLine, "*");
	strcat(tableLine, "\n");
	return tableLine;
}

char* produceTitle(char* pTitle, int pTitleLenght){
	int tittlePos = (TABLE_LINE_LENGTH - 2 - pTitleLenght)/2;	
	char* tableLine = (char*)malloc(TABLE_LINE_LENGTH*sizeof(char));
	tableLine[0] = '\0';
	strcat(tableLine, "*");
	int i;
	for (i = 1; i < tittlePos-1; i++){
		strcat(tableLine, " ");
	}
	strcat(tableLine, pTitle);
	for (i = tittlePos+pTitleLenght-1; i < TABLE_LINE_LENGTH-3; i++){
		strcat(tableLine, " ");
	}
	strcat(tableLine, "*\n");
	return tableLine;
}

void produceBasicLine(char* pBuffer, char* pName, char* pLine){
	char* space = fillStringWithSpace("", SPACE_LENGTH);

	strcat(pBuffer, "*");
	strcat(pBuffer, space);
	strcat(pBuffer, pName);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pLine);
}

void produceVariableLine(char* pBuffer, char* pName, char* pLine, char* pParam, char* pFunction, char* pIsUsed){
	char* space = fillStringWithSpace("", SPACE_LENGTH);

	produceBasicLine(pBuffer, pName, pLine);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pParam);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pFunction);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pIsUsed);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, "\n");
}

void produceFunctionLine(char* pBuffer, char* pName, char* pLine, char* pParam, char* pIsUsed){
	char* space = fillStringWithSpace("", SPACE_LENGTH);

	produceBasicLine(pBuffer, pName, pLine);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pParam);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pIsUsed);
	strcat(pBuffer, space);

	int i;
	for (i=FUNCTION_LINE_LENGTH-3; i < TABLE_LINE_LENGTH-3; i++){
		pBuffer[i] = ' ';
	}

	strcat(pBuffer, "*");
	strcat(pBuffer, "\n");
}

void produceTagLine(char* pBuffer, char* pName, char* pLine, char* pIsUsed){
	char* space = fillStringWithSpace("", SPACE_LENGTH);

	produceBasicLine(pBuffer, pName, pLine);
	strcat(pBuffer, space);
	strcat(pBuffer, "*");
	strcat(pBuffer, pIsUsed);
	strcat(pBuffer, space);

	int i;
	for (i=TAG_LINE_LENGTH-3; i < TABLE_LINE_LENGTH-3; i++){
		pBuffer[i] = ' ';
	}
		
	strcat(pBuffer, "*");
	strcat(pBuffer, "\n");
}

char* getFinalLine(){
	char* buffer = (char*)malloc( TABLE_LINE_LENGTH * sizeof(char));
	buffer[0] = '\0';
	int i;
	for (i=0; i < (TABLE_LINE_LENGTH-2); i++){
		strcat(buffer, "*");
	}
	strcat(buffer, "\n");
	return buffer;
}

void saveSymbolTable(){
	Symbol* symbol;
	char* tableLine;

	Node* iNode = symbolTable->head;

	char (*variables[symbolCount]);
	char (*functions[symbolCount]);
	char (*tags[symbolCount]);
	int variablesIndex = 0;
	int functionsIndex = 0;
	int tagsIndex = 0;

	while (iNode != 0){

		symbol = (Symbol*)iNode->value;
		tableLine = (char*)malloc(TABLE_LINE_LENGTH * sizeof(char));
		tableLine[0] = '\0';

		char* name = fillStringWithSpace(symbol->name, ID_LENGTH);
		char* decLine;
		if (symbol->declarationLine != -1){
			decLine = intToString(symbol->declarationLine);
		} else {
			decLine = (char*)malloc(3*sizeof(char));
			strcpy(decLine, "NA");
		}
		
		char* line = fillStringWithSpace(decLine, LINE_LENGTH);
		char* isUsed = fillStringWithSpace(symbol->isUsed != 0?"Si":"No", IS_USED_LENGTH);

		if (symbol->type == VARIABLE){
			
			char* parameter = fillStringWithSpace(symbol->function!=0?"Si":"No", PARAM_LENGTH);

			char* function;
			if (symbol->function != 0){
				function = fillStringWithSpace(symbol->function->name, ID_LENGTH);
			} else {
				function = fillStringWithSpace("NA", ID_LENGTH);
			}

			produceVariableLine(tableLine, name, line, parameter, function, isUsed);

			free(name); free(decLine); free(line); free(isUsed); free(parameter); free(function);

			variables[variablesIndex++] = tableLine;

		} else if (symbol->type == FUNCTION){

			char* parameter;

			if (symbol->parameter != 0){
				parameter = fillStringWithSpace(symbol->parameter->name, ID_LENGTH);
			} else {
				parameter = fillStringWithSpace("NA", ID_LENGTH);
			}

			produceFunctionLine(tableLine, name, line, parameter, isUsed);
			free(name); free(decLine); free(line); free(isUsed); free(parameter);
			functions[functionsIndex++] = tableLine;

		} else if (symbol->type == TAG){
			produceTagLine(tableLine, name, line, isUsed);

			free(name); free(decLine); free(line); free(isUsed);
			tags[tagsIndex++] = tableLine;

		}
		iNode = iNode->next;
	}	

	saveTableAux(variables, functions, tags, variablesIndex, functionsIndex, tagsIndex);

}

void saveTableAux(char** pVariables, char** pFunctions, char** pTags, int pVarCount, int pFunctCount, int pTagsCount){
	openFile("../TablaSimbolos.txt");

	char* divLine = getFinalLine();
	char* varTitle = produceTitle("Variables", 9);
	char* varDescription = produceVarDescription();
	char* funTitle = produceTitle("Funciones", 9);
	char* funDescription = produceFunDescription();
	char* tagTitle = produceTitle("Etiquetas", 9);
	char* tagDescription = produceTagDescription();

	int i;

	writeToFile(divLine);
	writeToFile(varTitle);
	writeToFile(divLine);
	writeToFile(varDescription);

	for (i=0; i < pVarCount; i++){
		writeToFile(pVariables[i]);
		free(pVariables[i]);
	}

	writeToFile(divLine);
	writeToFile(funTitle);
	writeToFile(divLine);
	writeToFile(funDescription);

	for (i=0; i < pFunctCount; i++){
		writeToFile(pFunctions[i]);
		free(pFunctions[i]);
	}

	writeToFile(divLine);
	writeToFile(tagTitle);
	writeToFile(divLine);
	writeToFile(tagDescription);

	for (i=0; i < pTagsCount; i++){
		writeToFile(pTags[i]);
		free(pTags[i]);
	}

	writeToFile(divLine);

	closeFile();
}

void initTable(){
	symbolTable = (SymbolTable*)malloc(sizeof(SymbolTable));
	symbolCount = 0;
	symbolTable->head = 0;
}

void freeTable(){
	Node* iNode = symbolTable->head;
	Node* tmp;
	while (iNode != 0){
		freeSymbol((Symbol*)iNode->value);
		tmp = iNode;
		iNode = iNode->next;
		free(tmp);
	}
	free(symbolTable);
}

void addSymbolToTable(Symbol* pSymbol){
	Node* node = (Node*)malloc(sizeof(Node));
	initNode(node);

	node->value = pSymbol;
	node->previous = 0;
	node->next = symbolTable->head;

	if (symbolTable->head != 0){
		symbolTable->head->previous = node;
	}

	symbolTable->head = node;
}

Symbol* newIDSymbol(char* pName){
	Symbol* symbol = newSymbol();
	symbol->name = pName;
	return symbol;
}

Symbol* newNumberSymbol(int pNum){
	int *num = (int*)malloc(sizeof(int));
	*num = pNum;
	Symbol* symbol = newSymbol();
	symbol->value = pNum;
	return symbol;
}

Symbol* newSymbol(){
	symbolCount++;
	Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
	initSymbol(symbol);
	addSymbolToTable(symbol);
	return symbol;
}