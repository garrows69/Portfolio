#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Verify Roll() from die.h works")
{
	Die die;

	for (int i = 0; i < 10; ++i)
	{
		die.roll();
		REQUIRE(die.rolled_value() >= 0);
		REQUIRE(die.rolled_value() <= 6);
	}
}

TEST_CASE("Verify roll_value() from roll.h works")
{
	Die d1, d2;
	Roll roll_test(d1, d2);

	for (int i = 0; i < 10; ++i)
	{
		roll_test.roll_die();
		REQUIRE(roll_test.roll_value() >= 1);
		REQUIRE(roll_test.roll_value() <= 12);
	}
}

/*
NEEDS WORK
*/
TEST_CASE("Verify Shooter returns a roll and result is within 1-12")
{
	Die d1, d2;
	Shooter shooter;
	Roll* roll;
	std::vector<Shooter> values;

	for (int i = 0; i < 15; ++i)
	{
		roll = shooter.shoot(d1, d2);
		
		REQUIRE(shooter.shoot(d1, d2) == roll);
	}
}