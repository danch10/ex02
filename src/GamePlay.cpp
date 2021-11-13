#include <iostream>
#include <cstdlib> // for std::system()
#include <conio.h>
#include <Windows.h>
#include "GamePlay.h"
#include "FileHandler.h"
#include "Board.h"
#include "Characters.h"
#include "Tiles.h"

enum Keys
{
	KB_Escape = 27,
	SpecialKey = 112,
};

enum SpecialKeys
{
	KB_Up = 72,
	KB_Down = 80,
	KB_Left = 75,
	KB_Right = 77,
};

void gamePlay::start()
{
	FileHandler file;
	Board board;
	Characters character;
	Tiles tile;

	for(int level = 1 ; level <= 3 ; level++ )

	while (! gameOver())
	{
		buildBoard(file, board, character, tile);

		startPlay(character, board);
	
		
	}
}

void gamePlay::buildBoard(FileHandler& file, Board board, Characters character, Tiles tile)
{	
	file.openFile();

	board.buildMap(file, character, tile);

	board.printMap();
}


void gamePlay::startPlay( Characters& character, const Board board)
{
	bool validMove = false;

	while (!validMove)
	{
		auto c = _getch();
		switch (c)
		{
		case KB_Up:
			goUp(character);
			break;

		case KB_Down:
			goDown(character);
			break;

		case KB_Left:
			goLeft(character);
			break;

		case KB_Right:
			goRight(character);
			break;

		case 'p':
			character.switchCharacter();
			break;
		
		case KB_Escape:
			
			gamePlay play;
			play.gameOver();
			break;

		default:
			std::cout << "press a valid key to move\n";
			break;
		}
	}
}

void gamePlay::printCharcterAndLevel()
{
}

bool gamePlay::gameOver() const
{
	return false;
}

void gamePlay::goRight(Characters& character, const Board board)
{
	int i = 0, j = 1;
	character.move(board, i, j);
}

void gamePlay::goLeft(Characters& character, const Board board)
{
	int i = 0, j = -1;
	character.move(board, i, j);
}

void gamePlay::goUp(Characters& character, const Board board)
{
	int i = 1, j = 0;
	character.move(board, i, j);
}

void gamePlay::goDown(Characters& character, const Board board)
{
	int i = 1, j = 0;
	character.move(board, i, j);
}


//void gamePlay::end()
//{
//	std::cout << "exiting game";
//	exit(EXIT_SUCCESS);
//}
