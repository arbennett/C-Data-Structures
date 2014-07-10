/*
 * linklist.h
 *
 *  Created on: Jul 9, 2014
 *      Author: robot
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

struct node* createLinkedList(int val);
struct node* addToFront(int val);
struct node* addToBack(int val);
struct node* getHead();
struct node* getNthNode(int N);
struct node* searchFor(int N);


#endif /* LINKLIST_H_ */
