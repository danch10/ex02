#pragma once
#include <fstream>

class FileHandler {

public:

	bool openFile();

	Board readBoard();


private:

	std::ifstream m_ifs;
};

