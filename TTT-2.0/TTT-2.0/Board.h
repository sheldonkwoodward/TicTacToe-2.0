#pragma once
#include<iostream>
using namespace std;

class Board {
private:
	char board[3][3];
public:
	Board()
	{
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				board[y][x] = ' ';
			}
		}
	}

	char getVal(int x, int y);
	void setVal(char val, int x, int y);
	char checkLittleWin();
};