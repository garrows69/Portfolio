/*********************
Name: Max Macigewski
Coding 03
Purpose: This program creates an int stack and does various modifications and testing.
**********************/

#include "stack.h"

Stack::Stack()
{
	top = -1;
}

int Stack::pop()
{
	if (isEmpty())
	{
		throw - 1; //throws an error for stack underflow
	}
	else
	{
		//deletes the top most element from the stack
		int d = stack[top--];
		return d;
	}
}

int Stack::peek()
{
	//returns whatever is at the top of stack
	return stack[top];
}

bool Stack::push(int x)
{
	bool passed;
	if (top >= (STACKSIZE - 1)) //checks to see if top is above max stack size
	{
		passed = false;
	}
	else
	{
		//if top is below
		stack[++top] = x;
		passed = true;
	}
	return passed;
}

bool Stack::isEmpty()
{
	return top < 0 ? true : false; //ternary operator
}