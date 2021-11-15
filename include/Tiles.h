#pragma once

#include <vector>
#include "Location.h"


class Board;
class Characters;

struct Node2{

	Node2(Location& location, char tile);

	Location m_location;
	char m_tile ;
};

class Tiles {

public:
	
	void addTile(const Node2& tile);

	void getTiles(const int& , const int& , const char& );

	void clearTile(const int& );

	int getCellNum(const char& , const Location& location) const;

	Location teleportDes(const int& , const int&) const;

	Board insertTiles(Board& board);

private:

	std::vector<Node2> m_tiles;
};
