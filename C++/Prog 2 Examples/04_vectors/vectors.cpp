#include "vectors.h"

/*
Write a value return function get_max_from_vector with a const reference 
vector of intsparameter that returns the max value in a vector

@param numbers is a const reference to a vector of integers
@return the max value in the vector
*/


int get_max_from_vector(const std::vector<int>& nums)
{
	auto iMax{ 0 };

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > iMax)
		{
			iMax = nums[i];
		}
	}
	return iMax;
}



/*
Write a function named is_prime with an integer parameter that
given a number returns true if prime or false if not prime

@param number: Any whole number
@return: bool if prime False if not
*/

bool is_prime(int num)
{
	auto bIsPrime{ true };
	for (int i = 2; i <= num / 2; ++i)
	{
		if (num % i == 0)
		{
			bIsPrime = false;
		}
	}
	return bIsPrime;
}

/*
Write a a function named vector_of_primes with an integer parameter
that given a number returns all the prime numbers up to the number

Example given number 10 returns a vector with elements 2,3,5,7,

@param int integer value
@return vector of ints containing prime values up to a value

Make sure to use the is_prime function to determine if current 
number is prime.
*/


std::vector<int> vector_of_primes(int num)
{
	std::vector<int> iPrimeList;

	for (int i = 2; i < num; ++i) //starts at 2 so it does not include 0/1(due to them already being prime)
	{
		if (is_prime(i))
		{
			iPrimeList.push_back(i);
		}
	}
	return iPrimeList;
}
