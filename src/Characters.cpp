#include "..\include\Characters.h"
#include "..\include\Characters.h"
#include "Characters.h"
#include "Board.h"



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

void Characters::move(Board board, const int i, const int j)
{

	checkValidation(board, m_head->m_x + i, m_head->m_y + j);

	m_head->m_x = m_head->m_x + i;
	m_head->m_y = m_head->m_y + j;
}

bool Characters::checkValidation(Board board, const int i, const int j)
{
	bool valid;

	char c;
	c = board.mapCell(i, j);

	switch (m_head->m_c)
	{
	case 'K':
		if ((c == '=') || (c == '*') || (c == '!') || (c == '#'))
		{
			valid = false;
			break;
		}
		else if(c == 'X') 
		{

			break;
		}
		else if ( c == '@')
		{

			break;
		}
		else
		{
			valid = true;
			break;
		}
		

	case 'W':
		if ((c == '=') || (c == '*') || (c == '@') || (c == '#'))
		{
			valid = false;
			break;
		}
		else if (c == 'X')
		{

			break;
		}
		else if (c == '!')
		{

			break;
		}

	case 'T':
		if ((c == '=') || (c == '*') || (c == '!') || (c == '@'))
		{
			valid = false;
			break;
		}
		else if (c == 'X')
		{

			break;
		}
		else if (c == 'F')
		{
			valid = m_key = true;

			break;
		}
		else if (c == '#')
		{

			break;
		}
	case 'M':
		if ((c == '=') || (c == '!') || (c == '#') || (c == '@'))
		{
			valid = false;
			break;
		}
		else if (c == '*')
		{

			break;
		}
	}
}
