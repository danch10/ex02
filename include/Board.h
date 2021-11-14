#pragma once
#include <vector>


class Board {

public:

	Board();
	/*void clearBoard();*/

	void printMap() const;

	void getStaticMap(char c, int row, int col);

	char mapCell(const int i, const int j);





private:

	std::vector<std::vector<char>> m_map;

};