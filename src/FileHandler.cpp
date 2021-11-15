#include <iostream>
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

//------------------------------------------------------------------//

void FileHandler::buildBoard(Board& board, Characters& character, Tiles& tile)
{
	board = readBoard();

	character = readCharacters();

	tile = readTiles();

	board = tile.insertTiles(board);

	board = character.insertCharacters(board);
}

//------------------------------------------------------------------//

Board FileHandler::readBoard()
{
	Board staticMap;
	char c;

	if (openFile())
	{
		while(m_ifs.good())
		{
			c = m_ifs.get();

			if (c == '\n')
			{
				staticMap.addRow();
				continue;
			}

			if (!(c == '=') && !(c == '@') && !(c == ' '))
			{
				c = ' ';
			}			
			staticMap.getRow(c);
		}
		m_ifs.close();
	}
	return staticMap;
}

//------------------------------------------------------------------//

Characters FileHandler::readCharacters()
{
	Characters chr;
	char c;
	
	int row = 0, col = 0;

	if (openFile())
	{
		while (m_ifs.good())
		{
			c = m_ifs.get();

			if (c == '\n')
			{
				col = 0;
				row++;
				continue;
			}

			if ((c == 'K') || (c == 'W') || (c == 'T') || (c == 'M'))
			{
				chr.listCharacters(row, col, c);
			}
			col++;
		}
	}
	m_ifs.close();
	
	return chr;
}

//------------------------------------------------------------------//

Tiles FileHandler::readTiles()
{
	Tiles tile;
	char c;
	int row = 0, col = 0;

	if (openFile())
	{
		while ( m_ifs.good())
		{
			c = m_ifs.get();

			if (c == '\n')
			{
				col = 0;
				row++;
				continue;
			}

			if ((c == 'F') || (c == '!') || (c == '#') || (c == '*') || (c == 'X'))
			{
				tile.getTiles(row, col, c);
			}
			col++;
		}		
		m_ifs.close();
	}	
	return tile;
}