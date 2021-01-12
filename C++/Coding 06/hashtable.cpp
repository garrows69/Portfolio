/*********************
Name: Max Macigewski
Coding 06
Purpose: This program represents a hash table.
**********************/


#include "hashtable.h"

Hashtable::Hashtable()
{
    count = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        hashtable[i] = nullptr;
    }
}

bool Hashtable::insertEntry(int id, string data)
{
    bool success = false;

    int position = hash(id);
    if (id > 0 && !(data.empty()))
    {
        //if space is empty
        if (!hashtable[position])
        {
			//lazy create, only make if needed
            LinkedList* newList = new LinkedList;
            hashtable[position] = newList;
        }
        success = hashtable[position]->addNode(id, data); //gives data to linkedlist and populates
        if (success)
        {
          count++;
        }
    }
    else
    {
        success = false;
    }
    return success;
}

bool Hashtable::removeEntry(int id)
{
    bool success = false;
    int position = hash(id);
    if (hashtable[position]->deleteNode(id))
    {
        success = true;
    }

    return success;
}

string Hashtable::getData(int id)
{
    string data;
    Data* tmp = new Data;
    int position = hash(id);

    if (hashtable[position]->getNode(id, tmp))
    {
        data = tmp->data;
    }
    else
    {
        data = " ";
    }
    return data;
}

int Hashtable::getCount() { return count; }

void Hashtable::printTable()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        std::cout << "Entry " << i + 1 << ": ";
        if (hashtable[i] == nullptr)
        {
            std::cout << "EMPTY";
        }
        else
        { 
            hashtable[i]->printList();
        }
        std::cout << std::endl; 
    }
}


int Hashtable::hash(int id)
{
    return id % TABLESIZE;
}

Hashtable::~Hashtable()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		if(hashtable[i] != NULL)
		{
			LinkedList* list = hashtable[i];
			list->clearList();
		}
	}
}