/*********************
Name: Max Macigewski
Coding 05
Purpose: This program represents a double linked list.
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H



#include "data.h"

#include <iostream>
#include <string>


class LinkedList
{

public:

	LinkedList();

	bool addNode(int, string);
	bool deleteNode(int);
	bool getNode(int, Data*);
	bool clearList();
	bool exists(int);
	int getCount();
	void printList();

	~LinkedList();

private:

	bool connectTail(int, string, Node*);
	bool connectHead(int, string);
	bool connectMid(int, string, Node*);
	Node* head;

};

#endif // !LINKED_LIST_H