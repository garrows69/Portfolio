//#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"


using std::cout; using std::cin;

int main() 
{
	Tic_tac_toe_data data;

	std::unique_ptr<TicTacToeManager> manager = std::make_unique<TicTacToeManager>(data);
	
	string playerOption{ "" };

	bool isRunning{ true }, error{ true };
	int position{ 0 }, playerInt{ 0 };
	char option{ ' ' };



	//main loop
	while (isRunning)
	{

		cout << "Tic Tac Toe game 3 or 4: ";
		cin >> playerInt;
		
		std::unique_ptr<Tic_tac_toe> game;

		if (playerInt == 3)
		{
			game = std::make_unique<Tic_tac_toe_3>();

		}
		else if (playerInt == 4)
		{
			game = std::make_unique<tic_tac_toe_4>();
		}


		//allows for constant looping to get user to input X or O. So program wont blow up
		while (error)
		{
			cout << "Player 1, X or O: ";
			cin >> playerOption;
			try
			{
				game->start_game(playerOption);
				error = false;
				cout << "\n"; //to add a break in the text
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		}

		do
		{
			try
			{
				cin >> *game;
				cout << *game;
			}

			catch (Error e)
			{
				cout << e.get_message();
			}
		} while (!game->gameOver());

		if(game->gameOver() == true)
		{
			cout << "\nPlayer " << game->get_winner() << " has won the game!";

			manager->save_game(game);//saves game instance, causes error that I canno't figure out

			cout << "\n\n" << *manager; //displays board
			std::cout << "\nDo you want to play again(Y/n): ";
			cin >> option;
			std::cout << "\n"; //to add a break in text

			error = true; //allows for resetting of board

			isRunning = option == 'n' ? false : true;
		}
	}

	if (isRunning == false)
	{
		cout << *manager;
	}


	return 0;
}