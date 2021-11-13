#pragma once

struct Node {
	Node(int x, int y, char c, Node* next);
	int m_x;
	int m_y;
	char m_c;
	Node* m_next;
};

class Characters {

public:

	void getFirst(char c, int x, int y);
	void listCharacters(int x, int y, char c);
	void closeList();
	void switchCharacter();
	void move(Board board, const int i, const int j);
	bool checkValidation(Board board, const int i, const int j);

private:

	Node* m_head;
	Node* m_tail;
	bool m_key = false;

};
