//cpp
#include "tic_tac_toe_data.h"

void Tic_tac_toe_data::save_games(const std::vector<std::unique_ptr<Tic_tac_toe>>& games)
{

	std::ofstream file_out(file_name, std::ios_base::trunc);

	for (auto& x : games) //for each vector of tic tac toe
	{
		for (auto& c : x.get()->get_pegs())
		{
			file_out << c; //write char to string
		}

		file_out << x.get()->get_winner(); //writes get winner
		file_out << "\n"; //new line
	}
	
	file_out.close(); //closes file
}

//ERROR BLOCK

std::vector<std::unique_ptr<Tic_tac_toe>> Tic_tac_toe_data::get_games()
{
	std::vector<std::unique_ptr<Tic_tac_toe>> boards; //unique vector of boards

	std::ifstream file_in(file_name); //open file

	string line; //string line

	std::vector<string> pegs; //pegs vector

	if (file_in.is_open()) //checks to make sure file is open
	{
		while (std::getline(file_in, line)) //while file_in is not end of line
		{
			for (char x : line) //for ever character in line
			{
				string addTo(1, x); //add it to a string starting at 1 to x(subscript)
				pegs.push_back(addTo); //adds string to pegs vector
			}
		}
	}

	string getWinner = pegs[pegs.size() - 1]; //gets the winner from the vector

	std::unique_ptr<Tic_tac_toe> board; //create unique ptr of board

	if (pegs.size() == 9) //if vector is size 9
	{
		std::unique_ptr<Tic_tac_toe_3> board = std::make_unique<Tic_tac_toe_3>(pegs, getWinner); //creates unique pointer while calling constructor with pegs and getWinner
	}
	else if (pegs.size() == 16)
	{
		std::unique_ptr<tic_tac_toe_4> board = std::make_unique<tic_tac_toe_4>(pegs, getWinner); //creates unique pointer while calling constructor with pegs and getWinner
	}

	//CAUSES AN ERROR
	//  boards.push_back(board); //adds board to boards vector

	file_in.close(); //close the file

	return boards;
}
