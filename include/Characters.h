#pragma once

class Board;
class Tiles;

#include "Location.h"
#include <vector>

struct Node {
	Node(const Location& location, char c);
	Location m_location;
	char m_c;
};

class Characters {

public:

	void addCharacter(const Node&);

	void listCharacters(int x, int y, char c);

	void closeList();

	void switchCharacter();

	void move(const Board& map, const int i, const int j);

	bool checkValidation(const char c);

	bool kingWon();

	void reAct(const char& c, Tiles& tile);

	Location characterLocation();
	
	Board insertCharacters(Board& board);

private:

	Location teleport(const Tiles& tile);

	std::vector<Node> m_characters;

	Node m_head;

	int m_chrNum;

	bool m_key = false;
	bool m_throne = false;
};
