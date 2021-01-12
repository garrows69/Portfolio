#include "die.h"

#include <iostream>
#include <random>

void Die::roll()
{

	std::random_device rd; //obtains random num from hardware
	std::mt19937 eng(rd()); //seeds the generator
	std::uniform_int_distribution<> dist(1, 6);


	roll_value = dist(eng); //assigns random valuie to roll

}
