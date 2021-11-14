#include <iostream>
#include "macros.h"
#include "FileHandler.h"
#include "Board.h"
#include "Characters.h"
#include "Tiles.h"

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

void FileHandler::readFromFile()
{
	
}
//m_ifs.good()

Board FileHandler::readBoard()
{
	Board staticMap;
	char c;

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
				c = m_ifs.get();

				if (!(c == '=') && !(c == '@') && !(c == ' ') && !(c == 'X'))
					c = ' ';

			staticMap.getStaticMap(c, i, j);
		}
	}
	
	return staticMap;
}

Characters FileHandler::readCharacters()
{
	Characters chr;
	bool firstCharacter = true;
	char c;

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			c = m_ifs.get();

			if (!(c == 'K') && !(c == 'W') && !(c == 'T') && !(c == 'M'))
				continue;

			if (firstCharacter)
			{
				chr.getFirst(c, i, j);
			}

			chr.listCharacters(c, i, j);
		}
	}
	chr.closeList();

	return chr;
}

Tiles FileHandler::readTiles()
{
	Tiles tile;
	char c;

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			c = m_ifs.get();

			if (!(c == 'F') && !(c == '!') && !(c == '#') && !(c == '*'))
				continue;

			tile.getTiles(c, i, j);
		}
	}
	return tile;
}
