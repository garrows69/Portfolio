/*********************
Name: Max Macigewski
Coding 04
Purpose: This program focuses on improving the stacks.
**********************/

#include "stack.h"

Stack::Stack()
{
    top = -1;
}

bool Stack::push(int ids, string info)
{
    bool passed;
    if (top >= (STACK_SIZE - 1))
    {
        passed = false;
    }
    else
    {
        if (ids > 0 && info.empty() == false) 
        {
            Data* myData = new Data; 
            myData->id = ids; 
            myData->information = info;
            ++top; 
            stack[top] = myData; 
            passed = true;
        }
        else { passed = false; } 
    }
    return passed;
}

bool Stack::pop(Data *myData) 
{
    bool passed;
    if (!isEmpty())
    {

        myData->id = stack[top]->id;
        myData->information = stack[top]->information;

        delete stack[top];

        top--;

        passed = true;
    }
    else 
    {
        myData->id = -1;
        myData->information = "";
        passed = false; 
    }
    return passed;
}


bool Stack::peek(Data& structure)
{
    bool passed;

    if (!isEmpty())
    {
        structure.id = stack[top]->id;
        structure.information = stack[top]->information;
        passed = true;
    }
    else
    {
        structure.id = -1;
        structure.information = "";
        passed = false;
    }

    
    return passed;
}


bool Stack::isEmpty()
{
    return top < 0 ? true : false;
}


Stack::~Stack()
{
    for (int i = top; i >= 0; i--)
    {
        delete stack[i];
    }
}