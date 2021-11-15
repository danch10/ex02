#pragma once

class Characters;
class Board;
struct Location;


class GamePlay {

public:

	void start();

	void endGame();

private:

	void startPlay(Characters& chr, const Board& b);

	void clearBoard();
};

