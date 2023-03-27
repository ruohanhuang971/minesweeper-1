#include "Board.h"

Board::Board(int num) {
	difficulty = num;
	if (difficulty == 0) {
		makeEasyBoard();
	} else if (difficulty == 1) {
		makeIntermediateBoard();
	} else {
		makeExpertBoard();
	}
}

void Board::makeEasyBoard() {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			showGrid[row][col] = 10;
		}
	}
}

void Board::makeIntermediateBoard() {
	for (int row = 0; row < 16; row++) {
		for (int col = 0; col < 16; col++) {
			showGrid[row][col] = 10;
		}
	}
}

void Board::makeExpertBoard() {
	for (int row = 0; row < 16; row++) {
		for (int col = 0; col < 30; col++) {
			showGrid[row][col] = 10;
		}
	}
}
