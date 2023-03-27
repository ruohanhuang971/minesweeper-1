#pragma once
#include <vector>
#include "Block.h"

class Board {
public:
	Board(int num);

	void makeEasyBoard();
	void makeIntermediateBoard();
	void makeExpertBoard();

private:
	int difficulty;
	std::vector<std::vector<Block>> grid;
	std::vector<std::vector<Block>> showGrid;
};

/*
	Beginner: 9X9 10 mines
	Intermediate: 16X16 40 mines
	Expert: 30X16 99 mines
*/

