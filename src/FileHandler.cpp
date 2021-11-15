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
	   return false;
   else
   {
	   return true;
	   std::cout << "file is open" << std::endl;
   }
	   
}

Board FileHandler::readBoard()
{
	Board staticMap;
	char c;
	std::vector<char> temp;

	if (openFile())
	{
		while(m_ifs.good())
		{
			c = m_ifs.get();

			if (c != '\n')
			{
			if (!(c == '=') && !(c == '@') && !(c == ' ') && !(c == 'X'))
				c = ' ';
			temp.push_back(c);
			}
			else
			{
				staticMap.getStaticMap(temp);
				temp.clear();
			}
		}
		m_ifs.close();
	}
	return staticMap;
}

Characters FileHandler::readCharacters()
{
	Characters chr;
	bool firstCharacter = true;
	char c;
	int i = 0, j = 0;

	if (openFile())
	{
		while (m_ifs.good())
		{
			c = m_ifs.get();

			if (c == '\n')
			{
				i = 0;
				j++;
				continue;
			}

			if (!(c == 'K') && !(c == 'W') && !(c == 'T') && !(c == 'M'))
			{
				chr.listCharacters(c, i, j);
				i++;
			}
		}
	}
		chr.closeList();

		m_ifs.close();
	
	return chr;
}

Tiles FileHandler::readTiles()
{
	Tiles tile;
	char c;
	int i = 0, j = 0;

	if (openFile())
	{
		while ( m_ifs.good())
		{
			c = m_ifs.get();

			if (c == '\n')
			{
				i = 0;
				j++;
				continue;
			}

			if (!(c == 'F') && !(c == '!') && !(c == '#') && !(c == '*'))
			{
				tile.getTiles(c, i, j);
			}
		}		
		m_ifs.close();
	}	
	return tile;
}

void FileHandler::buildBoard(Board& board, Characters& character, Tiles& tile)
{
		board = readBoard();

		character = readCharacters();

		tile = readTiles();

		board = tile.insertTiles(board);

		board = character.insertCharacters(board);
}
