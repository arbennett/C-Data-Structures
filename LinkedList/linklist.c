/**
 * A standard implementation of a singly linked list.
 *
 * @author: Andrew Bennett
 * @date:   July 9, 2014
 */

#include <stdio.h>

#include "linklist.h"

/* Globals */
struct node *head = NULL;
struct node *tail = NULL;

/* Something like a constructor */
struct node* createLinkedList(int val){
	head = (struct node*)malloc(sizeof(struct node));
	tail = (struct node*)malloc(sizeof(struct node));
	head->data = val;
	head->next = NULL;
	tail = head;
	return head;
}

/* Add a new node at the front */
struct node* addToFront(int val){
	if(head == NULL){
		return createLinkedList(val);
	}else{
		struct node temp = (struct node*)malloc(sizeof(struct node));
		temp->next = head;
		head = temp;
		return head;
	}
}

/* Add a new node at the end */
struct node* addToBack(int val){
	if(head == NULL){
		return createLinkedList(val);
	}else{
		struct node temp = (struct node*)malloc(sizeof(struct node));
		temp->data = val;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
		return tail;
	}
}

/* Gets the head node - pointless without scope declarations but for consistency */
struct node* getHead(){
	if(head == NULL){
		printf("Error: No linked list has been built!");
		return NULL;
	}else{
		return head;
	}
}

/* Get the Nth node */
struct node* getNthNode(int N){
	int i;
	struct node temp = (struct node*)malloc(sizeof(struct node));
	temp = getHead();
	for(i=0; i<N; i++){
		temp = temp->next;
		if( temp == NULL ){
			printf("Error: %i nodes do not exist!", N);
			return NULL;
		}
	}
	return temp;
}

/* Search for an integer value and return it, plus it's position */
struct node* searchFor(int N){
	struct node temp = (struct node*)malloc(sizeof(struct node));
	temp = getHead();
	while(temp != NULL){
		if(temp->data == N){
			return temp;
		}
		temp = temp->next;
	}
	printf("Could not find %i in the list.", N);
	return NULL;
}

/* The definition of a node in the list. For now we just store ints. */
struct node{
	int data;
	struct node *next;
};
