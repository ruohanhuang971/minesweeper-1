#pragma once
class Block {
public:
	Block() : mine(false), numMines(0) {};

	//return if Block has mine
	bool hasMine() { return mine; }
	//puts a mine at the Block
	void setMine() { mine = true; }

	//return how many mines are around the block
	int getNumMines() { return numMines; }
	//set how many mines are around the block
	void setNumMines(int num) { numMines = num; }

private:
	bool mine;
	int numMines;
};

