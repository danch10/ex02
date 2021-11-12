#include "..\include\Characters.h"
#include "..\include\Characters.h"
#include "Characters.h"






Node::Node(int x, int y, char c, Node* next)
	:m_x(x), m_y(y), m_c(c), m_next(next) {}


void Characters::listCharacters(int x, int y, char c)
{
	m_head = new Node(x, y, c, m_head);
}

void Characters::getFirst(char c, int x, int y)
{
	m_head->m_c = c ;
	m_head->m_x = x ;
	m_head->m_y = y ;
	m_head->m_next = NULL ;

	m_tail = m_head;
}

void Characters::closeList()
{
	m_tail->m_next = m_head;
}




