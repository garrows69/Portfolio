#include "vectors.h"

#include <iostream>
/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
	auto iOption{ 0 }, iNum{ 0 }, iPrime{ 0 }; //initializes the varibales
	auto bIsRunning{ true };
	auto cOption{ ' ' };
	std::vector<int> iUserValues;

	while (bIsRunning)
	{

		std::cout << "1: Get Max from vector";
		std::cout << "\n2: Get Primes";
		std::cout << "\nPick an option: ";

		std::cin >> iOption;

		if (iOption == 1)
		{
			while (iNum > -1)//will populate a vector until user enters a negative number
			{
				std::cout << "Input number to be inserted into vector(negative # to stop): ";
				std::cin >> iNum;

				if (iNum > -1) //a check to make sure the vector doesn't populate with a negative
				{
					iUserValues.push_back(iNum);
				}
			}
			std::cout << "\nMax number you entered: " << get_max_from_vector(iUserValues);
			iNum = 0; //clears the values in case it gets run again
			iUserValues.clear();
		}

		else if (iOption == 2)
		{
			std::cout << "Input a number: ";
			std::cin >> iPrime;

			std::vector<int> iPrimeVector = vector_of_primes(iPrime); //stores the files

			std::cout << "\nList of prime numbers: ";

			for (auto i : iPrimeVector)
			{
				std::cout << i << ", ";
			}
		}

		std::cout << "\n\nDo you want to continue(y/n)";
		std::cin >> cOption;

		if (cOption == 'n')
		{
			std::cout << "Program Ending";
			bIsRunning = false;
		} else { std::cout << "\n"; } //new line for formatting
	}

	return 0;
}