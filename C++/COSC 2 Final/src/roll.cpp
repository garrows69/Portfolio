#include "roll.h"
#include <iostream>

void Roll::roll_die()
{	
	die1.roll(); //rolls die1

	die2.roll(); //rolls die2

	rolled = true;//sets rolled to true

}

int Roll::roll_value() //not calling this properly??
{
	return (die1.rolled_value() + die2.rolled_value());
}