#ifndef NODE
#define NODE


typedef struct node Node;

struct node{
	Node* previous;
	Node* next;	
	void* value;
};

void initNode(Node* pNode);
#endif