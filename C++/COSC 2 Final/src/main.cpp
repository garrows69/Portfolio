#include "craps.h"

int main() 
{
	
	Die d1, d2;
	int crapNum;
	std::vector<Craps> games;
	int currentPlayer = 0;
	int cont = 0;

	std::cout << "Input number of craps players: ";
	std::cin >> crapNum;

	do
	{

		Craps crap(d1, d2, crapNum, currentPlayer);

		int play = 0;

		do
		{

			std::cout << "\nInput 1 to play and 0 to stop: ";
			std::cin >> play;

			if (play != 0)
			{
				crap.shoot_dice();
			}

		} while ((crap.game_over() == false) && (play == 1));

		currentPlayer = crap.get_next_player();

		games.push_back(crap);

		std::cout << "\nInput 1 to continue, 0 to stop: ";
		std::cin >> cont;

		if (cont != 1)
		{
			std::cout << "Craps ganes: " << crap;
		}

	} while (cont == 1);

	return 0;
}