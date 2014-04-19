#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

struct symbol;
typedef struct symbol Symbol;

#include "Symbol.h"
#include "Node.h"

typedef struct symbol_table SymbolTable;

extern const int NUMBER;
extern const int ID;
extern const int TAG;

struct symbol_table {
	Node* head;
};

void initTable(SymbolTable* pTable);
void freeTable(SymbolTable* pTable);
void addSymbolToTable(Symbol* pSymbol, SymbolTable* pTable);
void newNumberSymbol(SymbolTable* pTable, int pNum);
void newIDSymbol(SymbolTable* pTable, char* pName);
Symbol* newSymbol(SymbolTable* pTable);
Symbol* searchNumberSymbol(SymbolTable* pTable, int pNum);
Symbol* searchIDSymbol(SymbolTable* pTable, char* pID);

#endif