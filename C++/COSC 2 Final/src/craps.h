#ifndef CRAPS_H
#define CRAPS_H

#include "shooter.h"

class Craps
{
public:

	Craps(Die& d1, Die& d2, int player_cnt, int shooter_i) : die1(d1), die2(d2), shooter_indx(shooter_i) 
	{
		for (int i = 0; i < player_cnt; ++i)
		{
			Shooter shootVec;
			shooters.push_back(shootVec);
		}
	}

	bool game_over();

	void shoot_dice();

	int get_next_player() { return shooter_indx; }

	friend std::ostream& operator<<(std::ostream& out, Craps& craps);

private:

	std::vector<Shooter> shooters; //initialize with constructor player_cnt and shooter

	Die& die1;
	Die& die2;
	Roll* roll{}; //used in shoot_dice()

	int point{ 0 };
	int shooter_indx;

	bool come_out_phase{ true };
	bool point_phase{ false };
	
	bool seven_out(); //return rolled_value compared to 7
	bool craps(); //return roll rolled_value equap to 2,3 or 12
	bool natural(); //return roll rolled_valued equal to 7 or 11
	bool come_out_roll(); //return craps or natural
	bool rolled_point(); //return roll rolled_value equal to point

	void set_next_player(); 
};


#endif // !CRAPS_