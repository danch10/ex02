#include <iostream>
#include "GamePlay.h"
#include "FileHandler.h"
#include "Board.h"


void gamePlay::start()
{

	while (! gameOver())
	{
		buildBoard();

		startPlay();
			
	}

	

}

void gamePlay::buildBoard()
{
	FileHandler file;
	Board board;
	
	file.openFile();

	board.buildMap(file);

	board.printMap();
}

void gamePlay::startPlay()
{


}

bool gamePlay::gameOver() const
{


	return false;
}



//void gamePlay::end()
//{
//	std::cout << "exiting game";
//	exit(EXIT_SUCCESS);
//}
