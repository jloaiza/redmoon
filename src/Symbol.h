#ifndef SYMBOL
#define SYMBOL

#include "SymbolTable.h"

struct symbol_table;
typedef struct symbol_table SymbolTable;

typedef struct symbol Symbol;

struct symbol{
	int type;
	int value;
	int block;
	int isDeclarated;
	int isInitialized;
	int isUsed;
	char* name;
	int declarationLine;	
	Symbol* parameter;
	Symbol* function;
};

void initSymbol(Symbol* pSymbol);
void freeSymbol(Symbol* pSymbol);

#endif