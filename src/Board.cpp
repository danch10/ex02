#include <iostream>
#include "Board.h"
#include "Characters.h"
#include "Tiles.h"
#include "io.h"


void Board::clearMap()
{
	m_map.clear();
}

//------------------------------------------------------------------//

void Board::addRow()
{
	m_map.push_back(m_row);

	m_row.clear();
}

bool Board::mapBoarders(const Location& location) const
{
	bool valid;

	if (!((location.row >= 0) && 
		
		(location.row < (m_map.size() ))) ||

		!((location.col >= 0) &&
		
		(location.col < (m_map[0].size()) )) )
		
		valid = false;
	else
		valid = true;

	return valid;
}

//------------------------------------------------------------------//

void Board::dinamicCell(const char c, const int row, const int col)
{
	m_map[row][col] = c;
}

//------------------------------------------------------------------//

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

//------------------------------------------------------------------//

void Board::printMap() const
{
	int i, j;

	for (i = 0; i < m_map.size() ; i++)
	{
		for (j = 0; j < m_map[i].size() ; j++)

		std::cout << m_map[i][j]; 

		std::cout << std::endl;
	}

	std::cout << "====================================="<< std::endl;
}

//------------------------------------------------------------------//

void Board::getRow(const char c)
{
	m_row.push_back(c);
}

//------------------------------------------------------------------//

char Board::mapCell(const int i, const int j) const
{
	char c;

	c = m_map[i][j];

	return c;
}