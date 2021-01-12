/*********************
Name: Max Macigewski
Coding 07
Purpose: This program represents a binary search tree.
**********************/
//use g++ -I ./ *.cpp -o a.out


#include "bintree.h"

BinTree::BinTree()
{
    root = NULL;
    count = 0;
}

bool BinTree::isEmpty()
{
    bool success;

    //ternary
    success = count <= 0 ? true : false;

    return success;
}

bool BinTree::getRootData(Data* node)
{
    bool success;

    if (root)
    {
        node->id = root->data.id;
        node->information = root->data.information;
    }
    else
    {
        node->id = -1;
        node->information = " ";
    }

    return success;
}

int BinTree::getCount()
{
    return count;
}

void BinTree::displayTree()
{
    std::cout << "DISPLAY TREE" << std::endl;
    std::cout << "==============================================" << std::endl;

    if (isEmpty())
    {
        std::cout << "Tree is empty" << std::endl;
    }
    else
    {
        std::cout << "Tree is NOT empty" << std::endl;
    }

    std::cout << "Height: " << getHeight() << std::endl;
    std::cout << "Node count: " << count << std::endl;

    std::cout << "\nPre-Order Traversal" << std::endl;
    displayPreOrder();

    std::cout << "\nIn-Order Traversal" << std::endl;
    displayInOrder();

    std::cout << "\nPost-Order Traversal" << std::endl;
    displayerPostOrder();
    std::cout << std::endl;
}


//************************PUBLIC API***************************

void BinTree::clear()
{
    clear(root);
    count = 0;
}

bool BinTree::addNode(int id, string data)
{
    bool success;
    DataNode* temp;

    if (id > 0 && !data.empty()) //&& !contains(id))
    {
        DataNode* node = new DataNode;
        node->data.id = id;
        node->data.information = data;
        node->left = NULL;
        node->right = NULL;
        success = addNode(node, &root);
    }
    else { success = false; }

    return success;
}

bool BinTree::removeNode(int id)
{
    bool success;
    int tempcount = count;

    root = removeNode(id, root);

    if (count < tempcount)
    {
        success = true;
    }
    else { success = false; }

    return success;
}

bool BinTree::getNode(Data* node, int id)
{
    bool success;
    if (id > 0)
    {
        success = getNode(node, id, root);
    } 
    else { success = false; }

    return success;
}

bool BinTree::contains(int id)
{
    bool success;
    if (id >= 0)
    {
        success = contains(id, root);
    } 
    else { success = false; }

    return success;
}

int BinTree::getHeight()
{
    int height = getHeight(root);

    return height;
}

void BinTree::displayPreOrder()
{
    displayPreOrder(root);
}

void BinTree::displayerPostOrder()
{
    displayerPostOrder(root);
}

void BinTree::displayInOrder()
{
    displayInOrder(root);
}

//******************PRIVATE API*******************

void BinTree::clear(DataNode* temproot)
{
    if (temproot != NULL)
    {
        clear(temproot->left);
        clear(temproot->right);
        delete(temproot);

        //maybe shorten
        if (temproot->left != NULL)
        {
            temproot->left = NULL;
        }
        if (temproot->right != NULL)
        {
            temproot->right = NULL;
        }
        temproot = NULL;
    }
}


bool BinTree::addNode(DataNode* newNode, DataNode** root)
{
    bool success;

    if (!(*root))
    {
        *root = newNode;
        (*root)->data.id = newNode->data.id;
        (*root)->data.information = newNode->data.information;
        count++;
        success = true;
    }
    else
    {
        if (newNode->data.id < (*root)->data.id)
        {
            addNode(newNode, &(*root)->left);
        }
        if (newNode->data.id > (*root)->data.id)
        {
            addNode(newNode, &(*root)->right);
        }
    }

    return success;
}

DataNode* BinTree::removeNode(int id, DataNode* temproot)
{

    if (temproot)
    {
        if (id < temproot->data.id)
        {
            temproot->left = removeNode(id, temproot->left);
        }
        else if (id > temproot->data.id)
        {
            temproot->right = removeNode(id, temproot->right);
        }
        else
        {
            DataNode* temp;


            if (temproot->left == NULL)
            {
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }

            else if (temproot->right == NULL)
            {
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }
            else
            {
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
 }


//*********************HELPER****************************
DataNode* BinTree::minValueNode(DataNode* temproot)
{
    DataNode* current = temproot;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

//****************END OF HELPER**************

bool BinTree::getNode(Data* node, int id, DataNode* temproot)
{
    bool success;
    if (temproot)
    {
        if (id == temproot->data.id)
        {
            node->id = temproot->data.id;
            node->information = temproot->data.information;
            success = true;
        }
        else if (id < temproot->data.id)
        {
            success = getNode(node, id, temproot->left);
        }
        else if (id > temproot->data.id)
        {
            success = getNode(node, id, temproot->right);
        }
    }
    else { success = false; }

    return success;
}

bool BinTree::contains(int id, DataNode* temproot)
{
    bool success = false;
    if (!temproot) { success = false; }
    else if (temproot)
    {
        if (temproot->data.id == id)
        {
            success = true;
        }
        else if (id < temproot->data.id)
        {
            success = contains(id, temproot->left);
        }
        else if (id > temproot->data.id)
        {
            success = contains(id, temproot->right);
        }
    }

    return success;
}

int BinTree::getHeight(DataNode* temproot)
{
    int height = 0;
    int lh = 0;
    int rh = 0;

    if (temproot && count > 0)
    {
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
        height = std::max(lh, rh) + 1;
    }
    else { height = 0; }

    return height;
}

void BinTree::displayPreOrder(DataNode* temproot)
{
    if (temproot && !isEmpty())
    {
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->left)
        {
            displayerPostOrder(temproot->left);
        }
        if (temproot->right)
        {
            displayerPostOrder(temproot->right);
        }
    }
}

void BinTree::displayerPostOrder(DataNode* temproot)
{
    if (temproot && !isEmpty())
    {
        if (temproot->left)
        {
            displayerPostOrder(temproot->left);
        }
        if (temproot->right)
        {
            displayerPostOrder(temproot->right);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
    }
}

void BinTree::displayInOrder(DataNode* temproot)
{
    if (temproot && !isEmpty())
    {
        if (temproot->left)
        {
            displayInOrder(temproot->left);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->right)
        {
            displayInOrder(temproot->right);
        }
    }
}

BinTree::~BinTree()
{
    //do something cool
    clear(root);
}