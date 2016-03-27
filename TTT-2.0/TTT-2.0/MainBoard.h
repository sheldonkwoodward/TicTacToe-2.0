#pragma once
#include <iostream>
#include "Board.h"
#include "SWLib.h"
using namespace std;

class MainBoard {
private:
	Board miniBoards[3][3];
	int boardPosXY[2];
	bool chooseSpace;
public:
	//constructor
	MainBoard();

	//set and get functions
	void setBoardXY(int x, int y);
	int getBoardX();
	int getBoardY();
	void setChooseSpace(bool cs);
	bool getChooseSpace();

	//show board functions
	void showBoard(char turn);
	void setGuessOptions();
	void removeGuessOptions();
	void showMiniBoardVal(int X, int Y, int x, int y);

	//functions
	void setVal(char val, int x1, int y1, int x2, int y2);
	bool checkForVal(int x, int y);
	void tellBoardPos();
	char checkBigWin();
	char checkLittleWin(int x, int y);
};