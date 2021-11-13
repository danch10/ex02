#pragma once
#include <fstream>

class FileHandler {

public:

	bool openFile();

	void readBoard(Board& board, Characters& chr, Tiles& tile);


private:

	std::ifstream m_ifs;
};

