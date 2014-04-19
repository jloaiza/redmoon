#ifndef SYMBOL
#define SYMBOL

struct symbol_table;
typedef struct symbol_table SymbolTable;

#include "SymbolTable.h"

typedef struct symbol Symbol;

struct symbol{
	int type;
	int value;
	int scope;
	int isDeclarated;
	int isInitialized;
	int isUsed;
	char* name;
	int declarationLine;	
	int parameter;
};

void initSymbol(Symbol* pSymbol);
void freeSymbol(Symbol* pSymbol);

#endif