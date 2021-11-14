#include <iostream>
#include "macros.h"
#include "Board.h"
#include "Characters.h"
#include "Tiles.h"

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

void Board::getStaticMap(char c, int row, int col)
{
	m_map[row][col] = c;
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



//char Board::mapCell(const int i, const int j)
//{
//	char c;
//
//	c = m_map[i][j];
//
//	return c;
//}

//
//void Board::clearBoard()
//{
//
//}
