#pragma once

#include <fstream>
class Board;
class Characters;
class Tiles;


class FileHandler {

public:

	bool openFile();

	void readFromFile();

	Board readBoard();
	Characters readCharacters();
	Tiles readTiles();

private:

	std::ifstream m_ifs;
};

