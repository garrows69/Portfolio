//write include statements
#include "dna.h"

#include <iostream>
//#include <ctype>
//write using statements
using std::cout; using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	bool bIsRunning = true;
	int iOption = 0;
	std::string sDNA = "";
	char cKeepRun = ' ';

	while (bIsRunning)
	{
		cout << "Option 1: Get GC Content";
		cout << "\nOption 2: Get DNA Complement";
		cout << "\nInput Option: ";
		cin >> iOption;
		
		if (iOption == 1)
		{
			cout << "\nEnter DNA: ";
			cin >> sDNA;

			cout << "GC Content: " << get_gc_content(sDNA);
		}
		else if (iOption == 2)
		{
			cout << "\nEnter DNA: ";
			cin >> sDNA;
			
			cout << "DNA Complement: " << get_dna_complement(sDNA);
		}
		else if (iOption == 3)
		{
			cin >> sDNA;
			cout << get_reverse_string(sDNA);
		}
		
		cout << "\n\nDo you still want to continute?(Y/y)";
		cin >> cKeepRun;

		if (tolower(cKeepRun) == 'n')
		{
			cout << "Program Ending.";
			bIsRunning = false;
		}else { cout << "\n"; } //for formatting
	}

	return 0;
}