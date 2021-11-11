#include <iostream>
#include <vector>
#include "macros.h"
#include "Board.h"
#include "FileHandler.h"


void Board::clearBoard()
{
}

void Board::printBoard() const
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

void Board::getRow(const char& c)
{
	std::cout << c;

	if (c == '\n')
	{
		Board b;
		b.getMap();
		m_row.clear();
	}
	else
		m_row.push_back(c);
}

void Board::getMap()
{
	for (int i = 0; i < m_row.size(); i++)
		std::cout << m_row[i];
	m_map.push_back(m_row);
}
