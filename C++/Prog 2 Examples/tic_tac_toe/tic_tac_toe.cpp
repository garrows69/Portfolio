#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "tic_tac_toe.h"
#include <iostream>

//PUBLIC FUNCTIONS

void Tic_tac_toe::start_game(std::string first_player)
{
	if (first_player == "X" || first_player == "O")
	{
		player = first_player;
		clearBoard();
	}
	else { throw Error("Player must be X or O\n"); }
}

void Tic_tac_toe::mark_board(int position)
{
	if (position < 1 || position > 9 && pegs.size() == 9)
	{
		throw Error("Position must be 1 to 9.\n");
	}
	if (position < 1 || position > 16 && pegs.size() == 16)
	{
		throw Error("Position must be 1 to 16.\n");
	}
	else if (player == "")
	{
		throw Error("Must start game first.\n");
	} 
	else
	{
		pegs[(position - 1)] = player; //minus one for the index
		if (gameOver() == false) { set_next_player(); }
	}
}

std::ostream& operator<<(std::ostream& out, const Tic_tac_toe& t) 
{
	std::cout << "\n"; //formatting purposes
	for (std::size_t i = 0; i < t.pegs.size(); i += sqrt(t.pegs.size()))
	{
		out << t.pegs[i] << "|" << t.pegs[i + 1] << "|" << t.pegs[i + 2];

		if (t.pegs.size() == 16)
		{
			out << "|" << t.pegs[i + 3];
		}

		out << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Tic_tac_toe& b)
{
	int pos{ 0 };
	std::cout << "Player " << b.get_player() << " enter a position: ";
	in >> pos;
	b.mark_board(pos);

	return in;
}

bool Tic_tac_toe::gameOver()
{
	if (checkCheckRowWin() == true || checkColumnWin() == true || checkDiagonalWin() == true)
	{
		return true;
	}
	if (checkBoardFull() == true)
	{
		return true;
	}
	if ((get_winner() != "X" && get_winner() != "O") && checkBoardFull() == true)
	{
		winner = "C";
		return true;
	}
		return false;
	
}



//PRIVATE FUNCTIONS

void Tic_tac_toe::set_next_player()
{
	player = player == "X" ? "O" : "X"; //ternary for if player value is X it will set it to O, otherwise it will set it to X
}

bool Tic_tac_toe::checkColumnWin()
{
	return false;
}

bool Tic_tac_toe::checkCheckRowWin()
{
	return false;
}

bool Tic_tac_toe::checkDiagonalWin()
{
	return false;
}

bool Tic_tac_toe::checkBoardFull() //checks board if its full, if there is a space it is not full.
{
	for (auto& peg : pegs)
	{
		if (peg == " ")
		{
			return false;
		}
	}

	return true;
}

void Tic_tac_toe::clearBoard()
{
	for (auto &peg : pegs) //makes peg modifiable which is the element of pegs
	{
		peg = " ";
	}
}

void Tic_tac_toe::setWinner()
{
	winner = get_player() == "X" ? "O" : "X";
}

#endif