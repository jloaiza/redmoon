#include "Node.h"

void initNode(Node* pNode){
	pNode->next = 0;
	pNode->previous = 0;
	pNode->value = 0;
}