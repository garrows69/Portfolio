//h
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <fstream>

class Tic_tac_toe_data
{

public:

	void save_games(const std::vector<std::unique_ptr<Tic_tac_toe>>& games); //passes by reference but stops it from being edited

	std::vector<std::unique_ptr<Tic_tac_toe>> get_games();

private:

	string file_name = "save_games.dat";

};


#endif // !