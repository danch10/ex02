#pragma once
#include <vector>


class Board {

public:

	Board();
	void clearBoard();
	void printMap() const;
	void buildMap(FileHandler& filefile,
					Characters character, Tiles tile);
	void getMap(char c, int x, int y);
	char mapCell(const int i, const int j);

private:

	std::vector<std::vector<char>> m_map;

};