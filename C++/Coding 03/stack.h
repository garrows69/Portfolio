/*********************
Name: Max Macigewski
Coding 03
Purpose: This program creates an int stack and does various modifications and testing.
**********************/

#ifndef STACK_H
#define STACK_H

#define STACKSIZE 10

class Stack
{
public:
	//constructor
	Stack();

	//functions
	int pop();
	int peek();
	bool push(int);
	bool isEmpty();

private:

	int top;
	int stack[STACKSIZE];

};

#endif