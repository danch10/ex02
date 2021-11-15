#include <iostream>
#include "Board.h"
#include "Characters.h"
#include "Tiles.h"
#include "io.h"

Board::Board()
{
	for (int i = 0; i < 10 ; i++)
	{
		std::vector<char> temp;

		for (int j = 0; j < 10 ; j++)
			temp.push_back(' ');

		m_map.push_back(temp);
	}
}

void Board::clearMap()
{
	m_map.clear();
}

void Board::getStaticMap(std::vector<char>& row)
{
	m_map.push_back(row);
}

void Board::dinamicCell(const char c, const int row, const int col)
{
	m_map[row][col] = c;
}

void Board::upDateBoard(Characters& character, Tiles& tile)
{
	int row = character.characterLocation().row;
	int col = character.characterLocation().col;
		
	char c = m_map[row][col];

	if (c != ' ')
	{
		character.reAct(c, tile);
	}
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



char Board::mapCell(const int i, const int j) const
{
	char c;

	c = m_map[i][j];

	return c;
}
