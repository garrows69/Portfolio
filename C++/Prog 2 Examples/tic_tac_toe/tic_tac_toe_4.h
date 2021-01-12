//h
#ifndef TIC_TAC_TOE_4
#define TIC_TAC_TOE_4

#include "tic_tac_toe.h"

#include <iostream>

class tic_tac_toe_4 : public Tic_tac_toe
{

public:

	tic_tac_toe_4() : Tic_tac_toe(4) {}

	tic_tac_toe_4(std::vector<string> p, string winner) : Tic_tac_toe(p, winner) {}


private:

	bool checkColumnWin();
	bool checkCheckRowWin();
	bool checkDiagonalWin();

};


#endif // !TIC_TAC_TOE_4
