/*********************
Name: Max Macigewski
Coding 03
Purpose: This program creates an int stack and does various modifications and testing.
**********************/

#include "main.h"

int main(int argc, char** argv) {
	
	Stack stack;

	/*
	* This following block test adding and removing elements from the stack
	*
	*/

	std::cout << "Testing removing and adding elements to stack\n" << std::endl;

	for (int i = 1; i < 6; i++)
	{
		if (stack.push(i) == true)
		{
			std::cout << "Successfully pushed: " << i << std::endl;
		}
	}
	std::cout << "\nConfirming the top: " << stack.peek() << std::endl;
	std::cout << "\nRemoving 2 elements from stack" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Removing: " << stack.pop() << std::endl;
	}
	std::cout << "\nConfirming the top: " << stack.peek() << std::endl;

	/*
	*This following block is to test stack underflow
	*
	*/

	std::cout << "\nTesting stack underflow\n" << std::endl;

	try
	{
		for (int i = 0; i < STACKSIZE; i++)
		{
			std::cout << "Removing: " << stack.pop() << std::endl;
		}
	}
	catch (int x)
	{
		std::cout << "Error: encountered a stack underflow: " << x <<  std::endl;
	}

	/*
	*This following block is to test stack overflow
	*
	*/

	std::cout << "\nTesting stack overflow\n" << std::endl;

	for (int i = 1; i <= 11; i++)
	{
		if (stack.push(i) == true)
		{
			std::cout << "Successfully pushed: " << i << std::endl;
		}
		else
		{
			std::cout << "Error: encountered stack overflow" << std::endl;
		}
	}

	/*
	*This following block is to test the peek function
	*
	*/

	std::cout << "\nTesting peek function(populating stack backwards this time)\n" << std::endl;

	try
	{
		//clears the stack
		for (int i = 0; i < STACKSIZE; i++)
		{
			stack.pop();
		}
	}
	catch (int x)
	{
		std::cout << "Stack underflow: " << x;
	}

	//populating stack
	for (int i = STACKSIZE; i > 0; i--)
	{
		stack.push(i);
	}
	
	//testing function
	for (int i = 0; i < STACKSIZE; i++)
	{
		std::cout << "Top of stack: " << stack.peek() << std::endl;
		stack.pop();
	}
	
}