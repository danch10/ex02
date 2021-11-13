#pragma once


class gamePlay {

public:

	void start();

	//void switchPlayer();

	//void nextMove();

	//void nextLevel();

	//void end();

private:

	void buildBoard( FileHandler& file, Board board, Characters character, Tiles tile);

	bool gameOver() const;
	
	void printCharcterAndLevel();

	void startPlay(Characters& character, const Board board);

	void goRight(Characters& character, const Board board);

	void goLeft(Characters& character, const Board board);

	void goUp(Characters& character, const Board board);

	void goDown(Characters& character, const Board board);
};


