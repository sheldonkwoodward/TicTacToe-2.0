#include "MainBoard.h"

void MainBoard::showBoard()
{
	cout << endl << "                  " << (char)186 << "               " << (char)186 << endl;
	for (int Y = 0; Y < 3; Y++) {

		for (int i = 0; i < 3; i++) {
			if (i > 0) cout << "  " << (char)186;
			else cout << "   ";
			cout << "   " << miniBoards[Y][i].getVal(0, 0) << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(1, 0) << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(2, 0) << " ";
		}
		cout << endl;
		for (int y = 0; y < 2; y++) {
			cout << "     ";
			for (int x = 0; x < 3; x++) {
				cout << (char)196 << (char)196 << (char)196;
				cout << (char)197;
				cout << (char)196 << (char)196 << (char)196;
				cout << (char)197;
				cout << (char)196 << (char)196 << (char)196;
				if (x < 2) cout << "  " << (char)186 << "  ";
			}
			cout << endl;
			if (y == 0) {
				for (int i = 0; i < 3; i++) {
					if (i > 0) cout << "  " << (char)186;
					else cout << "   ";
					cout << "   " << miniBoards[Y][i].getVal(0, 1) << " " << (char)179;
					cout << " " << miniBoards[Y][i].getVal(1, 1) << " " << (char)179;
					cout << " " << miniBoards[Y][i].getVal(2, 1) << " ";
				}
				cout << endl;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (i > 0) cout << "  " << (char)186;
			else cout << "   ";
			cout << "   " << miniBoards[Y][i].getVal(0, 2) << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(1, 2) << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(2, 2) << " ";
		}

		if (Y < 2) {
			cout << endl << "                  " << (char)186 << "               " << (char)186 << endl;
			cout << "   ";
			cout << (char)205;
			for (int i = 0; i < 14; i++) cout << (char)205;
			cout << (char)206;
			for (int i = 0; i < 15; i++) cout << (char)205;
			cout << (char)206;
			for (int i = 0; i < 14; i++) cout << (char)205;
			cout << (char)205;
			cout << endl << "                  " << (char)186 << "               " << (char)186 << endl;
		}
	}
	cout << endl << "                  " << (char)186 << "               " << (char)186 << endl;
	cout << endl;


	//cout << "                " << (char)186 << "                 " << (char)186 << "                " << endl;
	//cout << "   " << miniBoards[0][0].getVal(0, 0) << " " << (char)179 << " " << miniBoards[0][0].getVal(1, 0) << " " << (char)179 << " " << miniBoards[0][0].getVal(2, 0) << "    " << (char)186 << "    " << miniBoards[0][1].getVal(0, 0) << " " << (char)179 << " " << miniBoards[0][1].getVal(1, 0) << " " << (char)179 << " " << miniBoards[0][1].getVal(2, 0) << "    " << (char)186 << "    " << miniBoards[0][2].getVal(0, 0) << " " << (char)179 << " " << miniBoards[0][2].getVal(1, 0) << " " << (char)179 << " " << miniBoards[0][2].getVal(2, 0) << "   " << endl;
	//cout << "  " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "  " << endl;
	//cout << "   " << miniBoards[0][0].getVal(0, 1) << " " << (char)179 << " " << miniBoards[0][0].getVal(1, 1) << " " << (char)179 << " " << miniBoards[0][0].getVal(2, 1) << "    " << (char)186 << "    " << miniBoards[0][1].getVal(0, 1) << " " << (char)179 << " " << miniBoards[0][1].getVal(1, 1) << " " << (char)179 << " " << miniBoards[0][1].getVal(2, 1) << "    " << (char)186 << "    " << miniBoards[0][2].getVal(0, 1) << " " << (char)179 << " " << miniBoards[0][2].getVal(1, 1) << " " << (char)179 << " " << miniBoards[0][2].getVal(2, 1) << "   " << endl;
	//cout << "  " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "  " << endl;
	//cout << "   " << miniBoards[0][0].getVal(0, 2) << " " << (char)179 << " " << miniBoards[0][0].getVal(1, 2) << " " << (char)179 << " " << miniBoards[0][0].getVal(2, 2) << "    " << (char)186 << "    " << miniBoards[0][1].getVal(0, 2) << " " << (char)179 << " " << miniBoards[0][1].getVal(1, 2) << " " << (char)179 << " " << miniBoards[0][1].getVal(2, 2) << "    " << (char)186 << "    " << miniBoards[0][2].getVal(0, 2) << " " << (char)179 << " " << miniBoards[0][2].getVal(1, 2) << " " << (char)179 << " " << miniBoards[0][2].getVal(2, 2) << "   " << endl;
	//cout << "                " << (char)186 << "                 " << (char)186 << "                " << endl;
	//
	//cout << (char)205;
	//for (int i = 0; i < 15; i++) cout << (char)205;
	//cout << (char)206;
	//for (int i = 0; i < 17; i++) cout << (char)205;
	//cout << (char)206;
	//for (int i = 0; i < 15; i++) cout << (char)205;
	//cout << (char)205 << endl;

	//cout << "                " << (char)186 << "                 " << (char)186 << "                " << endl;
	//cout << "   " << miniBoards[1][0].getVal(0, 0) << " " << (char)179 << " " << miniBoards[1][0].getVal(1, 0) << " " << (char)179 << " " << miniBoards[1][0].getVal(2, 0) << "    " << (char)186 << "    " << miniBoards[1][1].getVal(0, 0) << " " << (char)179 << " " << miniBoards[1][1].getVal(1, 0) << " " << (char)179 << " " << miniBoards[1][1].getVal(2, 0) << "    " << (char)186 << "    " << miniBoards[1][2].getVal(0, 0) << " " << (char)179 << " " << miniBoards[1][2].getVal(1, 0) << " " << (char)179 << " " << miniBoards[1][2].getVal(2, 0) << "   " << endl;
	//cout << "  " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "  " << endl;
	//cout << "   " << miniBoards[1][0].getVal(0, 1) << " " << (char)179 << " " << miniBoards[1][0].getVal(1, 1) << " " << (char)179 << " " << miniBoards[1][0].getVal(2, 1) << "    " << (char)186 << "    " << miniBoards[1][1].getVal(0, 1) << " " << (char)179 << " " << miniBoards[1][1].getVal(1, 1) << " " << (char)179 << " " << miniBoards[1][1].getVal(2, 1) << "    " << (char)186 << "    " << miniBoards[1][2].getVal(0, 1) << " " << (char)179 << " " << miniBoards[1][2].getVal(1, 1) << " " << (char)179 << " " << miniBoards[1][2].getVal(2, 1) << "   " << endl;
	//cout << "  " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "  " << endl;
	//cout << "   " << miniBoards[1][0].getVal(0, 2) << " " << (char)179 << " " << miniBoards[1][0].getVal(1, 2) << " " << (char)179 << " " << miniBoards[1][0].getVal(2, 2) << "    " << (char)186 << "    " << miniBoards[1][1].getVal(0, 2) << " " << (char)179 << " " << miniBoards[1][1].getVal(1, 2) << " " << (char)179 << " " << miniBoards[1][1].getVal(2, 2) << "    " << (char)186 << "    " << miniBoards[1][2].getVal(0, 2) << " " << (char)179 << " " << miniBoards[1][2].getVal(1, 2) << " " << (char)179 << " " << miniBoards[1][2].getVal(2, 2) << "   " << endl;
	//cout << "                " << (char)186 << "                 " << (char)186 << "                " << endl;
	//
	//cout << (char)205;
	//for (int i = 0; i < 15; i++) cout << (char)205;
	//cout << (char)206;
	//for (int i = 0; i < 17; i++) cout << (char)205;
	//cout << (char)206;
	//for (int i = 0; i < 15; i++) cout << (char)205;
	//cout << (char)205 << endl;

	//cout << "                " << (char)186 << "                 " << (char)186 << "                " << endl;
	//cout << "   " << miniBoards[2][0].getVal(0, 0) << " " << (char)179 << " " << miniBoards[2][0].getVal(1, 0) << " " << (char)179 << " " << miniBoards[2][0].getVal(2, 0) << "    " << (char)186 << "    " << miniBoards[2][1].getVal(0, 0) << " " << (char)179 << " " << miniBoards[2][1].getVal(1, 0) << " " << (char)179 << " " << miniBoards[2][1].getVal(2, 0) << "    " << (char)186 << "    " << miniBoards[2][2].getVal(0, 0) << " " << (char)179 << " " << miniBoards[2][2].getVal(1, 0) << " " << (char)179 << " " << miniBoards[2][2].getVal(2, 0) << "   " << endl;
	//cout << "  " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "  " << endl;
	//cout << "   " << miniBoards[2][0].getVal(0, 1) << " " << (char)179 << " " << miniBoards[2][0].getVal(1, 1) << " " << (char)179 << " " << miniBoards[2][0].getVal(2, 1) << "    " << (char)186 << "    " << miniBoards[2][1].getVal(0, 1) << " " << (char)179 << " " << miniBoards[2][1].getVal(1, 1) << " " << (char)179 << " " << miniBoards[2][1].getVal(2, 1) << "    " << (char)186 << "    " << miniBoards[2][2].getVal(0, 1) << " " << (char)179 << " " << miniBoards[2][2].getVal(1, 1) << " " << (char)179 << " " << miniBoards[2][2].getVal(2, 1) << "   " << endl;
	//cout << "  " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "   " << (char)186 << "   " << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << "  " << endl;
	//cout << "   " << miniBoards[2][0].getVal(0, 2) << " " << (char)179 << " " << miniBoards[2][0].getVal(1, 2) << " " << (char)179 << " " << miniBoards[2][0].getVal(2, 2) << "    " << (char)186 << "    " << miniBoards[2][1].getVal(0, 2) << " " << (char)179 << " " << miniBoards[2][1].getVal(1, 2) << " " << (char)179 << " " << miniBoards[2][1].getVal(2, 2) << "    " << (char)186 << "    " << miniBoards[2][2].getVal(0, 2) << " " << (char)179 << " " << miniBoards[2][2].getVal(1, 2) << " " << (char)179 << " " << miniBoards[2][2].getVal(2, 2) << "   " << endl;
	//cout << "                " << (char)186 << "                 " << (char)186 << "                " << endl;

}

void MainBoard::setVal(char val, int x1, int y1, int x2, int y2)
{
	miniBoards[y1][x1].setVal(val, x2, y2);
	boardPosXY[0] = x2;
	boardPosXY[1] = y2;
}

int MainBoard::getBoardX()
{
	return boardPosXY[0];
}

int MainBoard::getBoardY()
{
	return boardPosXY[1];
}

bool MainBoard::checkForVal(int x, int y)
{
	if (miniBoards[boardPosXY[1]][boardPosXY[0]].getVal(x, y) == ' ')
		return false;
	else
		return true;
}

void MainBoard::tellBoardPos()
{
	//position Y
	cout << "You are playing in the ";
	if (getBoardY() == 0)
		cout << "upper";
	else if (getBoardY() == 1)
		cout << "middle";
	else if (getBoardY() == 2)
		cout << "lower";
	//position X
	if (getBoardX() == 0)
		cout << " left";
	else if (getBoardX() == 1)
		cout << " middle";
	else if (getBoardX() == 2)
		cout << " right";
	cout << " section" << endl;
}

char MainBoard::checkBigWin()
{
	for (int i = 0; i < 3; i++) {
		//check horizontal
		if (miniBoards[0][i].checkLittleWin() == miniBoards[1][i].checkLittleWin() && miniBoards[1][i].checkLittleWin() == miniBoards[2][i].checkLittleWin()) return miniBoards[0][i].checkLittleWin();
		//check vertical
		if (miniBoards[i][0].checkLittleWin() == miniBoards[i][1].checkLittleWin() && miniBoards[i][1].checkLittleWin() == miniBoards[i][2].checkLittleWin()) return miniBoards[i][0].checkLittleWin();
	}
	//check diagnol
	if (miniBoards[0][0].checkLittleWin() == miniBoards[1][1].checkLittleWin() && miniBoards[1][1].checkLittleWin() == miniBoards[2][2].checkLittleWin()) return miniBoards[0][0].checkLittleWin();
	if (miniBoards[0][2].checkLittleWin() == miniBoards[1][1].checkLittleWin() && miniBoards[1][1].checkLittleWin() == miniBoards[2][0].checkLittleWin()) return miniBoards[0][2].checkLittleWin();

	return ' ';
}
