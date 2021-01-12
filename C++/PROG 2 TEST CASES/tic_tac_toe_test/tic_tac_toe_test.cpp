#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over")
{
	std::unique_ptr<Tic_tac_toe> game = std::make_unique<Tic_tac_toe_3>();

	game->start_game("O");

	REQUIRE(game->gameOver() == false);
}

TEST_CASE("Test set first player to X")
{
	std::unique_ptr<Tic_tac_toe> game = std::make_unique<Tic_tac_toe_3>();

	game->start_game("X");

	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test set first player to O")
{
	std::unique_ptr<Tic_tac_toe> game = std::make_unique<Tic_tac_toe_3>();

	game->start_game("O");

	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test Mark Position accepts values from 1 to 9 only")
{
	std::unique_ptr<Tic_tac_toe> game = std::make_unique<Tic_tac_toe_3>();

	game->start_game("X");

	REQUIRE_THROWS_AS(game->mark_board(0), Error);
	REQUIRE_THROWS_AS(game->mark_board(10), Error);
}

TEST_CASE("Test game ends when board is full")
{
	std::unique_ptr<Tic_tac_toe> game = std::make_unique<Tic_tac_toe_3>();

	game->start_game("X");

	for (std::size_t i = 1; i < 9; ++i)
	{
		game->mark_board(i);
	}
	game->mark_board(9);
	REQUIRE(game->gameOver() == true);
}

TEST_CASE("Test win by first column", "[X wins first column]")
{ /* Tic Tac Toe Board
		123
		456
		789

	   First column win are user positions 1,4, and 7
vector view: 0, 3, and 6
  */
	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(1);//X        
	REQUIRE(board->gameOver() == false);
	board->mark_board(2);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(4);//X          
	REQUIRE(board->gameOver() == false);
	board->mark_board(5);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(7);//X
	//X wins
	REQUIRE(board->gameOver() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by first row", "[X wins first row]")
{ /* Tic Tac Toe Board
		123
		456
		789
  */
	   
	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(1);//X        
	REQUIRE(board->gameOver() == false);
	board->mark_board(5);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(2);//X          
	REQUIRE(board->gameOver() == false);
	board->mark_board(4);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(3);//X
	//X wins
	REQUIRE(board->gameOver() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{ /* Tic Tac Toe Board
		123
		456
		789
  */
	   
	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(4);//X        
	REQUIRE(board->gameOver() == false);
	board->mark_board(2);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(5);//X          
	REQUIRE(board->gameOver() == false);
	board->mark_board(7);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(6);//X
	//X wins
	REQUIRE(board->gameOver() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{ /* Tic Tac Toe Board
		123
		456
		789
  */

	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(7);//X        
	REQUIRE(board->gameOver() == false);
	board->mark_board(2);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(8);//X          
	REQUIRE(board->gameOver() == false);
	board->mark_board(3);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(9);//X
	//X wins
	REQUIRE(board->gameOver() == true);
}

TEST_CASE("Test win by diag top left", "[X wins first diag]")
{ /* Tic Tac Toe Board
		123
		456
		789
  */
	   
	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(1);//X        
	REQUIRE(board->gameOver() == false);
	board->mark_board(3);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(5);//X          
	REQUIRE(board->gameOver() == false);
	board->mark_board(7);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(9);//X
	//X wins
	REQUIRE(board->gameOver() == true);
}

TEST_CASE("Test win by diag bottom left", "[X wins first diag]")
{ /* Tic Tac Toe Board
		123
		456
		789
  */
	   
	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(7);//X        
	REQUIRE(board->gameOver() == false);
	board->mark_board(6);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(5);//X          
	REQUIRE(board->gameOver() == false);
	board->mark_board(2);//O          
	REQUIRE(board->gameOver() == false);
	board->mark_board(3);//X
	//X wins
	REQUIRE(board->gameOver() == true);
}

TEST_CASE("Test for no winner")
{ /* Tic Tac Toe Board
		123
		456
		789
  */
	   
	std::unique_ptr<Tic_tac_toe> board = std::make_unique<Tic_tac_toe_3>();
	board->start_game("X");
	REQUIRE(board->gameOver() == false);
	board->mark_board(2);//X  1      
	REQUIRE(board->gameOver() == false);
	board->mark_board(1);//O  2       
	REQUIRE(board->gameOver() == false);
	board->mark_board(3);//X  3      
	REQUIRE(board->gameOver() == false);
	board->mark_board(6);//O  4     
	REQUIRE(board->gameOver() == false);
	board->mark_board(5);//X  5
	REQUIRE(board->gameOver() == false);
	board->mark_board(8);//O  6      
	REQUIRE(board->gameOver() == false);
	board->mark_board(9);//X  7
	REQUIRE(board->gameOver() == false);
	board->mark_board(7);//O  8      
	REQUIRE(board->gameOver() == false);
	board->mark_board(4);//XX  9
	REQUIRE(board->gameOver() == true);

}


TEST_CASE("Verify Tic_tac_toe mark board function4")
{
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	REQUIRE_THROWS_AS(game4->mark_board(1), Error);
}

TEST_CASE("Verify Tic_tac_toe start game function4")
{
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	REQUIRE_THROWS_AS(game4->start_game("A"), Error);
}

TEST_CASE("Verify Tic_tac_toe set first player function X4")
{
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");

	REQUIRE(game4->get_player() == "X");
}

TEST_CASE("Verify Tic_tac_toe set first player function O4")
{
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("O");

	REQUIRE(game4->get_player() == "O");
}

TEST_CASE("Verify Tic_tac_toe test game flow O4")
{
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->get_player() == "X");

	game4->mark_board(4);
	REQUIRE(game4->get_player() == "O");

}

TEST_CASE("Verify Tic_tac_toe test game flow X4")
{
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("O");
	REQUIRE(game4->get_player() == "O");

	game4->mark_board(4);
	REQUIRE(game4->get_player() == "X");

}

TEST_CASE("Win by first column4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(5);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(6);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(9);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(13);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
	REQUIRE(game4->get_winner() == "X");
}

TEST_CASE("Win by second column4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(10);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(14);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by third column4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(15);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}
TEST_CASE("Win by fourth column4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(4);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(8);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(12);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(15);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by first row4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(4);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by second row4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(5);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(10);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(8);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by third row4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(9);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(10);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(12);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}
TEST_CASE("Win by fourth row4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(13);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(14);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(15);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by diagonally top left4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by diagonally bottom left4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(4);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(10);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(13);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("For no Winner4") {
	std::unique_ptr<Tic_tac_toe> game4 = std::make_unique<tic_tac_toe_4>();
	game4->start_game("X");
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(3);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(6);//X
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(5);//O        
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(8);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(10);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(12);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(11);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(13);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(14);//O          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(15);//X          
	REQUIRE(game4->gameOver() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->gameOver() == true);
}
