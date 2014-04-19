#include "Symbol.h"
#include <stdlib.h>

void initSymbol(Symbol* pSymbol){
	pSymbol->type = -1;
	pSymbol->value = 0;
	pSymbol->scope = -1;
	pSymbol->isDeclarated = 0;
	pSymbol->isInitialized = 0;
	pSymbol->isUsed = 0;
	pSymbol->name = 0;
	pSymbol->declarationLine = -1;
	pSymbol->parameter = 0;
}

void freeSymbol(Symbol* pSymbol){
	free(pSymbol->name);
	free(pSymbol);
}

