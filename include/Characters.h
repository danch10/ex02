#pragma once

struct Node {
	Node(int x, int y, char c, Node* next);
	int m_x;
	int m_y;
	char m_c;
	Node* m_next
};

class Characters {

public:

	void listCharacters(int x, int y, char c);
	void getFirst(char c, int x, int y);
	void closeList();

private:

	Node* m_head;
	Node* m_tail;

};
