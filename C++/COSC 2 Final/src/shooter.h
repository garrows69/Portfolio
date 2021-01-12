#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"

#include <iostream>
#include <vector>

class Shooter
{
public:

	Roll* shoot(Die& d1, Die& d2); //creates roll instance
	
	friend std::ostream& operator<<(std::ostream& out, Shooter& b);

private:

	std::vector<Roll*> rolls;

};


#endif // !SHOOTER_H
