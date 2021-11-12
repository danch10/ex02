#include <iostream>
#include <fstream>
#include "FileHandler.h"
#include "Board.h"
#include "macros.h"
#include "Characters.h"
#include "Tiles.h"
#include <vector>

bool FileHandler::openFile()
{
   m_ifs.open("save_the_king.txt", std::ifstream::in);
    
   if (!m_ifs.is_open())
   {
	   return false;
   }
   else

	   return true;
}


Board FileHandler::readBoard() 
{ 
	Board board;
	Characters chr;
	Tiles tile;
	char c;
	int i = 0, j = 0;
	bool firstDone = false ;
	while (m_ifs.good())
	{

		c = m_ifs.get();

		/*if ((c == '@') || (c == ' ') || (c == 'X') || (c == '='))
			board.getMap(c, i, j);*/

		if (c == '\n')
		{
			j++;
			i = 0;
			continue;
		}

		if ((c == '*') || (c == '#') || (c == 'F') || (c == '!'))
		{
			tile.getTiles(i, j, c);
		}
		else if ((c == 'K') || (c == 'T') || (c == 'M') || (c == 'W'))
		{
			if (!firstDone)
				chr.getFirst(c, i, j);
			else
				chr.listCharacters(c, i, j);
		}

			board.getMap(c, i, j);

	}
	chr.closeList();

	return board;
}