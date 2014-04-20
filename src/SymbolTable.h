#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include "Symbol.h"
#include "Node.h"

struct symbol;
typedef struct symbol Symbol;

typedef struct symbol_table SymbolTable;

struct symbol_table {
	Node* head;
};

extern const int NUMBER;
extern const int VARIABLE;
extern const int FUNCTION;
extern const int TAG;

int symbolCount;

SymbolTable* symbolTable;

void initTable();
void freeTable();
void addSymbolToTable(Symbol* pSymbol);
Symbol* newNumberSymbol(int pNum);
Symbol* newIDSymbol(char* pName);
Symbol* newSymbol();
void saveSymbolTable();

#endif