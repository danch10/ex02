#pragma once


class gamePlay {

public:

	void start();

	//void switchPlayer();

	//void nextMove();

	void endGame();

private:

	void buildBoard(FileHandler& file, Board& board, Characters& character, Tiles& tile);

	bool gameOver() const;

	void startPlay(Characters& chr);

	void go(Characters& player, const int i, const int j);



};

