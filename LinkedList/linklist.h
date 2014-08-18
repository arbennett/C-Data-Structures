/**
 * Write here about what's going on
 */

typedef struct _node{
	int data;
	struct _node* next;
} node;

void initList();
node* getNthNode(int);
node* searchFor(int);
void addToFront(int);
void addToBack(int);
node* deleteValue(int);
void printNode(node*);
void printList();
