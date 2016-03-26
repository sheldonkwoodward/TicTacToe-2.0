#pragma once
#include <iostream>
#include "Board.h"
#include "SWLib.h"
using namespace std;

class MainBoard {
private:
	Board miniBoards[3][3];
	int boardPosXY[2];
public:
	MainBoard()
	{
		boardPosXY[0] = 1;
		boardPosXY[1] = 1;
	}

	void showBoard();
	void setVal(char val, int x1, int y1, int x2, int y2);
	int getBoardX();
	int getBoardY();
	bool checkForVal(int x, int y);
	void tellBoardPos();
	char checkBigWin();
	char checkLittleWin(int x, int y);
};