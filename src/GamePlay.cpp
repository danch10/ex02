#include <iostream>
#include <cstdlib> 
#include <conio.h>
#include "GamePlay.h"
#include "FileHandler.h"
#include "Board.h"
#include "Characters.h"
#include "Tiles.h"
#include "Location.h"

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

void GamePlay::start()
{
	FileHandler file;
	Board board;
	Characters character;
	Tiles tile;

	for (int level = 1; level <= 3; level++)
	{
		file.buildBoard(board, character, tile);

		while (!character.kingWon())
		{
			board.printMap();

			startPlay(character, board);

			board.clearMap();

			board = file.readBoard();

			board = tile.insertTiles(board);

			board.upDateBoard(character, tile);

			board = character.insertCharacters(board);
			
			clearBoard();
		}
	}
}

void GamePlay::startPlay(Characters& chr, const Board& b)
{
	bool validPlay = false;
	int row ;
	int col ;

	while (!validPlay)
	{
		auto c = _getch();

		switch (c)
		{
		case KB_Up:
			row = 1;
			col = 0;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case KB_Down:
			row = -1;
			col = 0;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case KB_Left:
			row = 0;
			col = -1;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case KB_Right:
			row = 0;
			col = 1;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case 'p':
			chr.switchCharacter();
			validPlay = true;
			break;
		
		case KB_Escape:
			endGame();
			validPlay = true;

		default:
			std::cout << "press a valid key to move\n";
			break;
		}
	}
}

void GamePlay::clearBoard()
{
	system("cls");
}

void GamePlay::endGame()
{
	std::cout << "exiting game";
	exit(EXIT_SUCCESS);
}
