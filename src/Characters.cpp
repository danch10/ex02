#include "Characters.h"
#include "Board.h"
#include "Tiles.h"
#include "GamePlay.h"
#include "Location.h"

Node::Node(const Location& location, char c)
	:m_location(location), m_c(c) {}

//------------------------------------------------------------------//

void Characters::listCharacters(int x, int y, char c)
{
	Location loc(x, y);

	 Node newCharacter(loc, c);

	 addCharacter(newCharacter);
}

//------------------------------------------------------------------//

void Characters::addCharacter(const Node& chr)
{
	m_characters.push_back(chr);
}

//------------------------------------------------------------------//

Board Characters::insertCharacters(Board& board)
{
	for (int i = 0; i < m_characters.size() ; i++)
	{
		int row = m_characters[i].m_location.row;
		int col = m_characters[i].m_location.col;

		char c = m_characters[i].m_c;

		board.dinamicCell(c, row, col);
	}
	return board;
}

//------------------------------------------------------------------//

void Characters::closeList()
{
	m_chrNum = 0;

	m_head = m_characters[m_chrNum];
}

//------------------------------------------------------------------//

void Characters::switchCharacter()
{
	if (m_chrNum != (m_characters.size() - 1))
		m_chrNum++;
	else
		m_chrNum = 0;

	m_head = m_characters[m_chrNum];
}

//------------------------------------------------------------------//

Location Characters::teleport(const Tiles& tile)
{
	char c = 'X';

	int row = m_head.m_location.row;
	int col = m_head.m_location.col;

	m_head.m_location = tile.teleportDes(row, col);

	return m_head.m_location;
}

//------------------------------------------------------------------//

void Characters::move(const Board& map, const int i, const int j)
{
	char c;

	int row = m_head.m_location.row + i;
	int col = m_head.m_location.col + j;

	c = map.mapCell(row, col);

	if (checkValidation(c))
	{
		m_head.m_location.row = m_head.m_location.row + i;
		m_head.m_location.col = m_head.m_location.col + j;
	}
}

//------------------------------------------------------------------//

Location Characters::characterLocation()
{
	int row = m_head.m_location.row;
	int col = m_head.m_location.col;

	Location locate(row, col);

	return locate;
}

//------------------------------------------------------------------//

bool Characters::kingWon()
{
	return m_throne;
}

//------------------------------------------------------------------//

bool Characters::checkValidation(const char c)
{
	bool valid = false;

	switch (m_head.m_c)
	{
	case 'K':
		if ((c == ' ') || (c == '@') || (c == 'X') || (c == 'F'))
		{
			valid = true;
		}
		break;

	case 'W':
		if ((c == ' ') || (c == '!') || (c == 'X') || (c == 'F'))
		{
			valid = true;
		}
		break;

	case 'T':
		if (c == '#') 
		{
			if (m_key)
			{
				valid = true;
				m_key = false;
			}
		}

		if ((c == ' ') || (c == 'X') || (c == 'F'))
		{
			valid = true;
		}
		break;

	case 'M':
		if ((c == ' ') || (c == '*') || (c == 'X') || (c == 'F'))
		{
			valid = true;
		}
		break;
	}
	return valid;
}

//------------------------------------------------------------------//

void Characters::reAct(const char& c, Tiles& tile)
{
	switch (m_head.m_c)
	{
	case 'K':
		if (c == '@')
		{
			m_throne = true;

			kingWon();
		}
		else if (c == 'X')
		{
			teleport(tile);
		}
		break;

	case 'W':
		if (c == '!')
		{
			int cell;
			cell = tile.getCellNum(c, m_head.m_location);
			tile.clearTile(cell);
			int row = m_head.m_location.row;
			int col = m_head.m_location.col;
			char newTile = 'W';
			tile.getTiles(row, col, newTile);
		}
		else if (c == 'X')
		{
			teleport(tile);
		}
		break;

	case 'T':
		if (c == '#')
		{
			int cell;
			cell = tile.getCellNum(c, m_head.m_location);
			tile.clearTile(cell);
		}
		else if (c == 'F')
		{
			m_key = true;
			int cell;
			cell = tile.getCellNum(c, m_head.m_location);
			tile.clearTile(cell);
		}
		else if (c == 'X')
		{
			teleport(tile);
		}
		break;
		
	case 'M':
		if (c == '*')
		{
			int cell;
			cell = tile.getCellNum(c, m_head.m_location);
			tile.clearTile(cell);
		}
		break;
	}
}