#pragma once
#include <vector>


class Board {

public:

	Board();
	void clearBoard();
	void printMap() const;
	void buildMap(FileHandler& file);
	void getMap(char c, int x, int y);

private:

	std::vector<std::vector<char>> m_map;

};