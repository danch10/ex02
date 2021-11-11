#include <iostream>
#include "GamePlay.h"
#include "FileHandler.h"
#include "Board.h"
//
//
//void gamePlay::start()
//{
//	FileHandler gameFile ;
//	Board gameBorad ;
//
//	//gameFile.openFile();
//
//
//	gameBorad.printBoard();
//
//	m_running = false;
//
//	while (!m_running)
//	{
//		end();
//	}
//
//}



void gamePlay::end()
{
	std::cout << "exiting game";
	exit(EXIT_SUCCESS);
}
