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

	//FileHandler gameFile ;
	//Board gameBorad ;

	////gameFile.openFile();


	//gameBorad.printBoard();

	//m_running = false;

	//while (!m_running)
	//{
	//	end();
	//}

}

void gamePlay::buildBoard()
{
	FileHandler file;
	Board board;
	
	file.openFile();

	board.buildMap();

	board.printMap();
}

bool gamePlay::gameOver() const
{

	return false;
}

void gamePlay::startPlay()
{
}




//void gamePlay::end()
//{
//	std::cout << "exiting game";
//	exit(EXIT_SUCCESS);
//}
