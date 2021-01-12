/*********************
Name: Max Macigewski
Coding 06
Purpose: This program represents a hash table.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    Hashtable table;
    // show it is empty by calling getCount and printTable
    std::cout << "Displaying table Count: " << table.getCount() << std::endl;
    std::cout << "\nPrinting Table" << std::endl;
    
    table.printTable();
    // try and put ALL the data into the table and show what happens
    std::cout << "\nAttempting to populate table\n" << std::endl;

    for (int i = 0; i < (sizeof(ids)/sizeof(*ids)); i++)
    {
        std::cout << "Inserting id: " << ids[i] << " and data: " << strs[i] << std::endl;
        if (table.insertEntry(ids[i], strs[i]))
        {
            std::cout << "Success" << std::endl;
        }
        else { std::cout << "failed" << std::endl; }
    }

    std::cout << "\nPrinting the Table\n" << std::endl;
    table.printTable();
    // continue using and testing your table, add and remove data,
    // make more test data if you need to.
    std::cout << "\nChecking data at random points\n" << std::endl;

    string data = table.getData(ids[1]);
    std::cout << "Data at " << ids[1] << " " << data << std::endl;

    data = table.getData(ids[2]);
    std::cout << "Data at " << ids[2] << " " << data << std::endl;

    data = table.getData(ids[3]);
    std::cout << "Data at " << ids[3] << " " << data << std::endl;

    std::cout << "\nDeleting some data and then printing table\n" << std::endl;

    if (table.removeEntry(ids[4]))
    {
        std::cout << "Successfully removed: " << ids[4] <<std::endl;
    }
    else
    {
        std::cout << "Could not remove the node" << std::endl;
    }

    if (table.removeEntry(ids[5]))
    {
        std::cout << "Successfully removed: " << ids[5] << std::endl;
    }
    else
    {
        std::cout << "Could not remove the node" << std::endl;
    }
    
    std::cout << "\nGetting count \n" << std::endl;
    std::cout << "Count: " << table.getCount() << std::endl;

    std::cout << "\nDisplaying table\n" << std::endl;

    table.printTable();

    
    
    return 0;
}
