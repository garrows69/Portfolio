//h
#ifndef TIC_TAC_TOE_3
#define TIC_TAC_TOE_3

#include "tic_tac_toe.h"

#include <iostream>

class Tic_tac_toe_3 : public Tic_tac_toe 
{
public:

	Tic_tac_toe_3() : Tic_tac_toe(3) { }//initializes the pegs to 9

	Tic_tac_toe_3(std::vector<string> p, string winner) : Tic_tac_toe(p, winner) {}//more code here, dont forget to pass p and winner to constructor 


private:

	bool checkColumnWin();
	bool checkCheckRowWin();
	bool checkDiagonalWin();

};

#endif // !TIC_TAC_TOE_3

