#pragma once

#include <vector>
#include "Location.h"
class Characters;
class Tiles;

class Board {

public:

	void clearMap();

	void upDateBoard(Characters& character, Tiles& tile);

	void printMap() const;

	void getRow(const char);

	void addRow();

	bool mapBoarders(const Location& ) const;

	void dinamicCell(const char, const int, const int);

	char mapCell(const int i, const int j) const;

private:

	std::vector<std::vector<char>> m_map;

	std::vector<char> m_row;
};