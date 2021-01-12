/*********************
Name: Max Macigewski
Coding 06
Purpose: This program represents a hash table.
**********************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "data.h"
#include <string>
#include <iostream>

#define TABLESIZE 15

class Hashtable
{
public:
    Hashtable();
    ~Hashtable();

    bool insertEntry(int, string);
    bool removeEntry(int);
    string getData(int);
    int getCount();
    void printTable();
    


private:
    int hash(int);
    int count;
    LinkedList* hashtable[TABLESIZE];
};

#endif // !HASHTABLE_H
