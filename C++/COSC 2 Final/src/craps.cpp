#include "craps.h"

#include <memory>

bool Craps::game_over()
{
	if (!come_out_phase)
	{
		if ((seven_out()) || (rolled_point()) && (point_phase))
		{
			if (seven_out()) //game is over
			{
				point = 0;
				point_phase = false;
				come_out_phase = true;
				set_next_player();
				return true;
			}
		}
	}
	return false;
}

void Craps::shoot_dice()
{
	Die* die1 = new Die();
	Die* die2 = new Die();

	roll = shooters[shooter_indx].shoot(*die1, *die2); //the * is to reference the mem address

	std::cout << "Rolled and roll -> " << roll->roll_value() << "\n";

	//inspect rolled value result
	if (come_out_phase && come_out_roll())
	{
		std::cout << "Come out roll phase: " << come_out_phase << "\n";
		if (natural())
		{
			std::cout << "Natural" << "\n";
		}
		else if (craps())
		{
			std::cout << "Craps" << "\n";
		}
	}
	else if (come_out_phase && !come_out_roll())
	{
		std::cout << "End of come out roll phase." << "\n";
		point = roll->roll_value();
		std::cout << "Must roll " << point << " before a 7" << "\n";
		come_out_phase = false;
	}
	else
	{
		std::cout << "Point phase: " << point_phase << "\n";
		if (rolled_point())
		{
			std::cout << roll->roll_value() << " Ends round." << "\n";
		}
		else
		{
			std::cout << roll->roll_value() << " did not roll point\n";
		}
	}

	delete die1;
	delete die2;

	die1, die2 = nullptr;
}

bool Craps::seven_out()
{
	if (roll->roll_value() == 7)
	{
		return true;
	}
	return false;
}

bool Craps::craps()
{
	if((roll->roll_value() == 2) || (roll->roll_value() == 3) || (roll->roll_value() == 12))
	return false;
}

bool Craps::natural()
{
	if (roll->roll_value() == 7 || roll->roll_value() == 11)
	{
		return true;
	}
	return false;
}

bool Craps::come_out_roll()
{
	if (natural())
	{
		return natural();
	}
	else if (craps())
	{
		return craps();
	}
	return false;
}

bool Craps::rolled_point()
{
	if (roll->roll_value() == point)
	{
		return true;
	}
	return false;
}

void Craps::set_next_player()
{

	if (shooter_indx == shooters.size() - 1)
	{
		shooter_indx = 0;
	}
	else { shooter_indx++; }

}

//FRIEND FUNCTION

std::ostream& operator<<(std::ostream& out, Craps& craps)
{

	for (auto& x : craps.shooters)
	{
		out << x;
	}

	return out;
}
