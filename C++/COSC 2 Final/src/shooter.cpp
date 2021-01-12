#include "shooter.h"

Roll* Shooter::shoot(Die& d1, Die& d2)
{

	Roll* roll = new Roll(d1, d2); //create dynamic instance of roll

	roll->roll_die(); //call roll_die
	
	rolls.push_back(roll); //adds roll with values to vector(referenced)

	return roll; //return roll instance(returns referenced address)
}

std::ostream& operator<<(std::ostream& out, Shooter& b)
{
	for (auto &x : b.rolls)
	{
		out << x->roll_value();
	}

	return out;
}
