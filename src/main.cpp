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
 
	return EXIT_SUCCESS;
}