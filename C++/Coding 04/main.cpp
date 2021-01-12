/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    Data structure;
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    std::cout << "\n\nTesting functions with empty stack (Will return 1 for true, 0 for false)" << std::endl;
    std::cout << "Testing isempty method: " << stack.isEmpty() << std::endl;
    std::cout << "Testing peek method: " << stack.peek(structure) << std::endl;
    std::cout << "Testing pop method: " << stack.pop(&structure) << std::endl;
        
    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack.
     */

    std::cout << "\n\nTesting push\n" << std::endl;
    for (int i = 0; i < (sizeof(ids)/sizeof(ids[0])); i++)
    {
        Data top;
        std::cout << "Adding test case: " << ids[i] << std::endl;
            if (stack.push(ids[i], data[i]) == true)
            {
                std::cout << "Successfuly added to stack." << std::endl;
            }
            else
            {
                std::cout << "Could not add to stack:" << std::endl;
            }
            if (stack.peek(top))
            {
                std::cout << "\nPeek: " <<" Id: " << top.id << " Info: " <<top.information << std::endl << std::endl;
            }
    }

    std::cout << "\n\nTesting pop\n" << std::endl;
    if (!(stack.isEmpty()))
    {
        Data top;
        std::cout << "Stack is not empty" << std::endl;
        for (int i = 0; i <= 4; i++)
        {
            if (stack.pop(&top))
            {
                std::cout << "Successfully removed: " << top.id << " Data: " << top.information << std::endl;
            }
        }
    }

    std::cout << "\n\nFinished testing " << std::endl;

    return 0;
}
