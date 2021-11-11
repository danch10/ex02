#include <iostream>
#include <fstream>
#include "FileHandler.h"
#include "Board.h"
#include "macros.h"
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
	char c;

	while (m_ifs.good())
	{
		c = m_ifs.get();
	}
}
