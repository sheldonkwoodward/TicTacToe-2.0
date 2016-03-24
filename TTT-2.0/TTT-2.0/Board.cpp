#include "Board.h"

char Board::getVal(int x, int y)
{
	//return 'X';
	return board[y][x];
}

void Board::setVal(char val, int x, int y)
{
	board[y][x] = val;
}

char Board::checkLittleWin()
{
	for (int i = 0; i < 3; i++) {
		//check horizontal
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
		//check vertical
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
	}
	//check diagnol
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

	return ' ';
}
