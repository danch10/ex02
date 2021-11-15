#include "Characters.h"
#include "Board.h"
#include "Tiles.h"
#include "GamePlay.h"
#include "Location.h"

Node::Node(const Location& location, char c, Node* next)
	:m_location(location), m_c(c), m_next(next) {}

void Characters::listCharacters(int x, int y, char c)
{
	Location loc(x, y);

	m_head = new Node(loc, c, m_head);

	if (m_head->m_next == NULL)
		m_tail = m_head;
}

Board Characters::insertCharacters(Board& board)
{
	for (int i = 0; i < 4; i++)
	{
		int row = m_head->m_location.row;
		int col = m_head->m_location.col;

		char c = m_head->m_c;

		board.dinamicCell(c, row, col);

		m_head = m_head->m_next;
	}

	return board;
}

Location Characters::teleport(const Tiles& tile)
{

	char c = 'X';

	int row = m_head->m_location.row ;
	int col = m_head->m_location.col ;

	m_head->m_location = tile.teleportDes(row, col);

	return m_head->m_location;
}

void Characters::closeList()
{
	m_tail->m_next = m_head;
}

void Characters::switchCharacter()
{
	m_head = m_head->m_next;
}

void Characters::move(const Board& map, const int i, const int j)
{
	char c;

	int row = m_head->m_location.row + i;
	int col = m_head->m_location.col + j;

	c = map.mapCell(row, col);

	if (checkValidation(c))
	{
		m_head->m_location.row = m_head->m_location.row + i;
		m_head->m_location.col = m_head->m_location.col + j;
	}
}

bool Characters::checkValidation(const char c)
{
	bool valid = false;

	switch (m_head->m_c)
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

bool Characters::kingWon()
{
	return m_throne;
}

void Characters::reAct(const char& c, Tiles& tile)
{
	switch (m_head->m_c)
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
			cell = tile.getCellNum(c, m_head->m_location);
			tile.clearTile(cell);
			int row = m_head->m_location.row;
			int col = m_head->m_location.col;
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
			cell = tile.getCellNum(c, m_head->m_location);
			tile.clearTile(cell);
		}
		else if (c == 'F')
		{
			m_key = true;
			int cell;
			cell = tile.getCellNum(c, m_head->m_location);
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
			cell = tile.getCellNum(c, m_head->m_location);
			tile.clearTile(cell);
		}
		break;
	}
}

Location Characters::characterLocation(Characters& character)
{
	int row = m_head->m_location.row;
	int col = m_head->m_location.col;

	Location locate(row, col);

	return locate;
}