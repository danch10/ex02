#include "..\include\Characters.h"
#include "Characters.h"
#include "Board.h"
#include "Tiles.h"
#include "GamePlay.h"



Node::Node(int x, int y, char c, Node* next)
	:m_x(x), m_y(y), m_c(c), m_next(next) {}

void Characters::listCharacters(int x, int y, char c)
{
	m_head = new Node(x, y, c, m_head);
}

Characters Characters::getFirst(char c, int x, int y)
{
	m_head->m_c = c ;
	m_head->m_x = x ;
	m_head->m_y = y ;
	m_head->m_next = NULL;

	m_tail = m_head;
}

void Characters::closeList()
{
	m_tail->m_next = m_head;
}

void Characters::switchCharacter()
{
	m_head = m_head->m_next;
}

void Characters::relocate(const int i, const int j)
{
	m_head->m_x = i;
	m_head->m_y = j;
}

void Characters::move(const int i, const int j)
{

	char c;
	c = board.mapCell(i, j);


	if (checkValidation(c)
	{
		relocate(m_head->m_x = m_head->m_x + i, m_head->m_y = m_head->m_y + j);
	}
}

bool Characters::checkValidation(const char c)
{
	bool valid = false;

	switch (m_head->m_c)
	{
	case 'K':
		if (KValidation())
		{
			relocate();
			valid = true;
		}
		break;

	case 'W':
		if (WValidation())
		{
			relocate();
			valid = true;
		}
		break;

	case 'T':
		if (TValidation())
		{
			relocate();
			valid = true;
		}
		break;

	case 'M':
		if (TValidation())
		{
			relocate();
			valid = true;
		}
		break;
	}
}

Board Characters::insertCharacters(Board& board)
{
	for (int i = 0; i < 4; i++)
	{
		int row = m_head->m_x;
		int col = m_head->m_y;
		char c = m_head->m_c;

		board.getStaticMap(c, row, col);
	}

	return board;
}

bool Characters::KValidation()
{
	if ((c == '=') || (c == '*') || (c == '!') || (c == '#'))
	{
		return false;
	}
	else if (c == 'X')
	{

	}
	else if (c == '@')
	{

	}
	else
	{
		return true;
	}
}

bool Characters::WValidation()
{
	if ((c == '=') || (c == '*') || (c == '@') || (c == '#'))
	{
		return false;
	}
	else if (c == 'X')
	{

	}
	else if (c == '!')
	{
	
	}
}

bool Characters::TingValidation()
{
	if ((c == '=') || (c == '*') || (c == '!') || (c == '@'))
	{
		return false;
	}
	else if (c == 'X')
	{
	
	}
	else if (c == 'F')
	{
	
	}
	else if (c == '#')
	{
	
	}
}

bool Characters::MingValidation()
{
	if ((c == '=') || (c == '!') || (c == '#') || (c == '@'))
	{
		return false;
	}
	else if (c == '*')
	{

	}
}

