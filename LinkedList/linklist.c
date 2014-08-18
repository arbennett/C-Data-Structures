
#include <stdio.h>
#include <limits.h>

#include "linklist.h"

#define SENTINEL INT_MAX

node *head;
node *tail;

/* Main method to show it works and run simple tests */
int main(){
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	initList();
	head->data = 0;
	int i;
	for(i=1; i<10; i++){
		addToBack(i);
	}
	searchFor(3);
	searchFor(123);
	printList();
	printf("%i\n",head->next->data);

	return 0;
}

/* Constructor like */
void initList(){
	head->data = NULL;
	tail->data = SENTINEL;
	head->next = tail;
	tail->next = head;
}

/* Add a new node at the front */
void addToFront(int val){
	node *temp;
	if(head == NULL){
		initList();
	}else{
		temp = (node*)malloc(sizeof(node));
		temp->next = head;
		temp->data = val;
		head = temp;
	}
}

/* Add a new node at the end */
void addToBack(int val){
	node *temp;
	if(head == NULL){
		initList();;
	}else{
		temp = (node*)malloc(sizeof(node));
		temp->data = SENTINEL;
		temp->next = NULL;
		tail->next = temp;
		tail->data = val;
		tail = temp;
	}
}

/* Go forward i nodes and return that one;
 * if there are not that many we just return
 * NULL and print an error message.*/
node* getNthNode(int i){
	node *temp = (node*)malloc(sizeof(node));
	if(head == NULL){
		initList();
	}
	temp = head;
	while(i>0){
		if(temp->next != tail){
			temp = temp->next;
			--i;
		}else{
			return NULL;
		}
	}
	return temp;
}

/* Search for an integer value and return it */
node* searchFor(int i){
	node *temp = (node*)malloc(sizeof(node));
	if(head == NULL){
		initList();
	}
	temp = head;
	while(temp->data != i && temp != tail){
		temp = temp->next;
	}
	if(temp->data == i){
		return temp;
	}else{
		printf("Could not find %i in the list.\n", i);
		return NULL;
	}
}

/* Delete the first occurrence of i in the list.  Only deletes one node.*/
node* deleteValue(int i){
	if(i == SENTINEL){
		printf("You cannot delete the tail node. Sorry.");
		return NULL;
	}
	node *temp = (node*)malloc(sizeof(node));
	node *deleted = (node*)malloc(sizeof(node));
	temp = searchFor(i);
	deleted = temp;
	temp = temp->next;
	return deleted;
}

/* Print the data in a node */
void printNode(node *n){
	printf("Data: %i \n", n->data);
}

/* Print out the list in order */
void printList(){
	node* temp = (node*)malloc(sizeof(node));
	temp = head;
	while(temp->data != SENTINEL){
		printNode(temp);
		temp = temp->next;
	}
}
