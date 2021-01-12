/*********************
Name: Max Macigewski
Coding 05
Purpose: This program represents a double linked list.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = NULL; 
}

bool LinkedList::addNode(int n, string str)
{
	bool passed = false;
	Node* newNode = new Node;
	Node* current = new Node;;
	Node* previous = new Node;

	if (n > 0 && !(str.empty()) && !exists(n))
	{
		if (head == NULL)
		{
			newNode->data.id = n;
			newNode->data.data = str;
			head = newNode;
			head->prev = NULL;
			head->next = NULL;
			passed = true;
		}
		else if (n < head->data.id)
		{
			passed = connectHead(n, str);
		}
		else
		{
			current = head;
			while (current != NULL && (n > current->data.id))
			{
				previous = current;
				current = current->next;
			}
			if (current == NULL)
			{
				passed = connectTail(n, str, previous);
			}
			else
			{
				passed = connectMid(n, str, current);
			}
		}
	}

	return passed;
}

bool LinkedList::connectTail(int id, string str, Node* previous)
{
	bool passed;
	Node* newNode = new Node;
	newNode->data.id = id;
	newNode->data.data = str;
	newNode->next = NULL;
	newNode->prev = previous;
	previous->next = newNode; 
	passed = true;
	return passed;
}

bool LinkedList::connectHead(int id, string str)
{
	Node* node = new Node;
	node->data.id = id;
	node->data.data = str;
	head->prev = node;
	node->next = head; 
	node->prev = NULL; 
	head = node; 

	return true;
}

bool LinkedList::connectMid(int n, string str, Node* node)
{
	Node* newNode = new Node;
	newNode->data.data = str;
	newNode->data.id = n;
	newNode->next = node;
	newNode->prev = node->prev;
	node->prev->next = newNode;
	node->prev = newNode;
	return true;
}


bool LinkedList::deleteNode(int n)
{
	bool passed = false;
	Node* current = new Node;
	current = head;

	while (current && current->data.id != n)
	{
		current = current->next;
	}

	if (current)
	{
		if (current == head)
		{
			head = head->next;
		}
		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}

		if (current->next)
		{
			current->next->prev = current->prev;
		}
		if (current->prev)
		{
			current->prev->next = current->next;
		}

		delete current;

		passed = true;
	}
	else
	{
		passed = false;
	}
	return passed;
}


bool LinkedList::getNode(int n, Data* data)
{
	bool passed;
	Node* tmp = new Node;

	if (n > 0 && exists(n))
	{
		tmp = head;
		while (tmp != NULL)
		{
			if (tmp->data.id == n)
			{
				data->id = tmp->data.id;
				data->data = tmp->data.data;
				passed = true;
			}
			tmp = tmp->next;
		}

	}

	return passed;
}

bool LinkedList::clearList()
{
	bool passed;
	Node* current = new Node;
	Node* next = new Node;
	current = head;

	if (head != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		head = NULL;
		passed = true;
	}
	else
	{
		passed = false;
	}
	return passed;
}

bool LinkedList::exists(int n)
{
	bool passed = false;
	Node* currentNode = new Node;

	if (n > 0)
	{
		if (head != NULL)
		{
			currentNode = head;
			while (currentNode != NULL)
			{
				if (currentNode->data.id == n)
				{
					passed = true;
				}
				currentNode = currentNode->next;
			}
		}
	}
	return passed;
}

int LinkedList::getCount()
{
	int count = 0;
	Node* currentNode = new Node;

	if (head != NULL)
	{
		currentNode = head;
		count++;
		while (currentNode = currentNode->next)
		{
			count++;
		}
	}
	return count;
}

void LinkedList::printList()
{
	Node* currentNode = new Node;
	Node* previous = new Node;

	if (head != NULL)
	{
			currentNode = head;
			int count = getCount();

			for (int i = 0; i < count; i++)
			{
				if (currentNode->next == NULL)
				{
					std::cout << currentNode->data.id;
				}
				else
				{
					std::cout << currentNode->data.id << "-->";
					currentNode = currentNode->next;
				}
			}
		}
}

LinkedList::~LinkedList()
{
	clearList();
}