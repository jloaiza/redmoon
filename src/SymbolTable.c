#include "SymbolTable.h"
#include "Utils.h"
#include <stdlib.h>

const int NUMBER = 0;
const int ID = 1;
const int TAG = 2;

void initTable(SymbolTable* pTable){
	pTable->head = 0;
}

void freeTable(SymbolTable* pTable){
	Node* iNode = pTable->head;
	Node* tmp;
	while (iNode != 0){
		freeSymbol((Symbol*)iNode->value);
		tmp = iNode;
		iNode = iNode->next;
		free(tmp);
	}
	free(pTable);
}

void addSymbolToTable(Symbol* pSymbol, SymbolTable* pTable){
	Node* node = (Node*)malloc(sizeof(Node));
	initNode(node);
	node->value = pSymbol;
	node->previous = 0;
	if (pTable->head == 0){
		pTable->head = node;
	} else {
		node->next = pTable->head;
		pTable->head->previous = node;
	}
}

void newIDSymbol(SymbolTable* pTable, char* pName){
	newSymbol(pTable)->name = pName;
}

void newNumberSymbol(SymbolTable* pTable, int pNum){
	int *num = (int*)malloc(sizeof(int));
	*num = pNum;
	newSymbol(pTable)->value = pNum;
}

Symbol* newSymbol(SymbolTable* pTable){
	Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
	initSymbol(symbol);
	addSymbolToTable(symbol, pTable);
	return symbol;
}

Symbol* searchNumberSymbol(SymbolTable* pTable, int pNum){
	Node* iNode = pTable->head;
	while (iNode != 0){
		if (((Symbol*)iNode->value)->type == NUMBER && *((int*)(((Symbol*)iNode->value)->value)) == pNum){
			return (Symbol*)(iNode->value);
		}
		iNode = iNode->next;
	}
	return 0;
}

Symbol* searchIDSymbol(SymbolTable* pTable, char* pID){
	Node* iNode = pTable->head;
	while (iNode != 0) {
		if (((Symbol*)iNode->value)->type == ID && strcomp(((Symbol*)iNode->value)->name, pID) == 0){
			return (Symbol*)(iNode->value);
		}
		iNode = iNode->next;
	}
	return 0;
}