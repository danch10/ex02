#pragma once


class gamePlay {

public:

	void start();

	//void switchPlayer();

	//void nextMove();

	//void nextLevel();

	//void end();

private:

	void buildBoard();

	bool gameOver() const;
	
	void startPlay();

};