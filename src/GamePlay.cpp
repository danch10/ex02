#include <iostream>
#include <cstdlib> 
#include <conio.h>
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

	while (1)
	{
		buildBoard(file, board, character, tile);

		startPlay(character);

		/*checkPlay();*/


	}

}

void gamePlay::buildBoard(FileHandler& file, Board& board, Characters& character, Tiles& tile)
{	
	if(file.openFile())
	{
		board = file.readBoard();
		
		character = file.readCharacters();

		tile = file.readTiles();

		board = tile.insertTiles(board);

		board = character.insertCharacters(board);

		board.printMap();
	}
}


void gamePlay::startPlay( Characters& chr)
{
	bool validMove = false;
	int row ;
	int col ;


	while (!validMove)
	{
		auto c = _getch();

		switch (c)
		{
		case KB_Up:
			row = 1;
			col = 0;
			go(chr, row, col);
			break;

		case KB_Down:
			row = -1;
			col = 0;
			go(chr, row, col);
			break;

		case KB_Left:
			row = 0;
			col = -1;
			go(chr, row, col);
			break;

		case KB_Right:
			row = 0;
			col = 1;
			go(chr, row, col);
			break;

		case 'p':
			chr.switchCharacter();
			break;
		
		case KB_Escape:
			endGame();

		default:
			std::cout << "press a valid key to move\n";
			break;
		}
	}
}

bool gamePlay::gameOver() const
{
	return false;
}

void gamePlay::go(Characters& player, const int i, const int j)
{
	player.move( i, j);
}

void gamePlay::endGame()
{
	std::cout << "exiting game";
	exit(EXIT_SUCCESS);
}
