/*********************
Name: Max Macigewski
Coding 04
Purpose: This program focuses on improving the stacks.
**********************/

#ifndef STACK_H
#define STACK_H

#include "data.h"
#define STACK_SIZE 10 

class Stack {

public:

    Stack();
    bool push(int, string);
    bool pop(Data*);
    bool peek(Data&);
    bool isEmpty();
    ~Stack();
    
private:

    int top; 
    Data *stack[STACK_SIZE]; 
};

#endif //STACK_H