#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll
{
public:

	Roll(Die& d1, Die& d2) : die1(d1), die2(d2) {}

	void roll_die();

	int roll_value(); //{ return (die1.rolled_value() + die2.rolled_value()); }

private:

	Die& die1;
	Die& die2;

	bool rolled{ false };

};

#endif // !ROLL_h