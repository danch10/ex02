#pragma once
#include <vector>


class Board {

public:

	void clearBoard();
	void printBoard()const;
	
	void getRow(const char& c);
	void getMap();
	

private:

	std::vector<std::vector<char>> m_map;

	std::vector<char> m_row;


};