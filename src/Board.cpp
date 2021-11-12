#include <iostream>
#include <vector>
#include "macros.h"
#include "Board.h"
#include "FileHandler.h"


Board::Board()
{
	for (int i = 0; i < MAX_ROW; i++)
	{
		std::vector<char> temp;

		for (int j = 0; j < MAX_COL; j++)
			temp.push_back(' ');

		m_map.push_back(temp);
	}
}

void Board::clearBoard()
{

}


void Board::printMap() const
{
	int i, j;

	for (i = 0; i < m_map.size() ; i++)
	{
		for (j = 0; j < m_map.size() ; j++)

		std::cout << m_map[i][j]; 

		std::cout << std::endl;
	}

	std::cout << "====================================="<< std::endl;
}

void Board::buildMap(FileHandler& file)
{
	file.readBoard();
}


void Board::getMap(char c, int x, int y)
{
	m_map[x][y] = c ;
}
