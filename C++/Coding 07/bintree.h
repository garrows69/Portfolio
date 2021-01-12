/*********************
Name: Max Macigewski
Coding 07
Purpose: This program represents a binary search tree. 
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <time.h>
#include <iostream>
#include <algorithm>

class BinTree
{
public:

    BinTree();

    bool isEmpty();
    bool getRootData(Data*);
    int getCount();
    void displayTree();

    ~BinTree();

    //public API
    void clear();
    bool addNode(int, string);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayerPostOrder();
    void displayInOrder();

private:

    DataNode* root;
    int count;

    //private API
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayerPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    //HELPER
    DataNode* minValueNode(DataNode*);
};




#endif /* BINTREE_BINTREE_H */

