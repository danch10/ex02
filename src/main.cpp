#include <iostream>

#include <cstdlib>

#include "GamePlay.h"
#include "FileHandler.h"
#include "Board.h"


int main()
{
	/*gamePlay play;

	play.start;*/

	Board board;
	FileHandler file;
	
	file.openFile();
	
	file.readBoard();

	//board.clearBoard();

	board.printBoard();
 
	return EXIT_SUCCESS;
}