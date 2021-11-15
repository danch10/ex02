#pragma once

#include <fstream>

class Board;
class Characters;
class Tiles;


class FileHandler {

public:

	bool openFile();

	void buildBoard(Board& board, Characters& character, Tiles& tile);

	Board readBoard();

	Characters readCharacters();
	
	Tiles readTiles();

private:

	std::ifstream m_ifs;

};

