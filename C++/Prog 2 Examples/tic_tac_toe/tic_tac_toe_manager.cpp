#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager(Tic_tac_toe_data & read) 
{
	games = read.get_games(); //Initalizes games vector to get_games()

	for (auto& x : games) //iterate games vector
	{
		x.get()->get_winner(); //Not sure how to update winner function when TicTacmanager doesn't extend tic tac toe
	}
}

//cpp
std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{

	for (auto& game : manager.games)
	{
		out << *game;
		
	}

	out << "\nX wins: " << manager.x_win << ", O wins: " << manager.o_win << ", ties: " << manager.ties << "\n";

	return out;
}


void TicTacToeManager::save_game(std::unique_ptr<Tic_tac_toe>& b)
{
	update_winner_count(b->get_winner());
	games.push_back(std::move(b)); //I think the error is here??
}

void TicTacToeManager::update_winner_count(std::string winner)
{
	if (winner == "X")
	{
		x_win++;
	}
	else if (winner == "O")
	{
		o_win++;
	}
	else { ties++; }
}

TicTacToeManager::~TicTacToeManager() //to save games
{
	data.save_games(games); //saves games to file
}