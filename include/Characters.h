#pragma once

class Board;
class Tiles;
#include "Location.h"

struct Node {
	Node(const Location& location, char c, Node* next);
	Location m_location;
	char m_c;
	Node* m_next;
};

class Characters {

public:

	void listCharacters(int x, int y, char c);

	void closeList();

	void switchCharacter();
	
	void move(const Board& map, const int i, const int j);

	bool checkValidation(const char c);

	bool kingWon();

	void reAct(const char& c, Tiles& tile);

	Location characterLocation(Characters& character);
	
	Board insertCharacters(Board& board);



private:

	Location teleport(const Tiles& tile);

	Node* m_head;
	Node* m_tail;
	bool m_key = false;
	bool m_throne = false;
};
