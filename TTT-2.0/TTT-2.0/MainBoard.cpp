#include "MainBoard.h"

//constructor
MainBoard::MainBoard()
{
	boardPosXY[0] = 1;
	boardPosXY[1] = 1;
	chooseSpace = false;
}

//set and get functions
void MainBoard::setBoardXY(int x, int y)
{
	boardPosXY[0] = x;
	boardPosXY[1] = y;

	if (checkLittleWin(boardPosXY[0], boardPosXY[1]) != ' ') chooseSpace = true;
}
int MainBoard::getBoardX()
{
	return boardPosXY[0];
}
int MainBoard::getBoardY()
{
	return boardPosXY[1];
}
void MainBoard::setChooseSpace(bool cs)
{
	chooseSpace = cs;
}
bool MainBoard::getChooseSpace()
{
	return chooseSpace;
}

//show board functions
void MainBoard::showBoard()
{
	if (!chooseSpace) setGuessOptions();

	string boardColor = "lightGray", selectedColor = "green";
	string XWinColor = "darkGray", OWinColor = "darkGray";

	cout << endl << "                  " << (char)186 << "               " << (char)186 << endl;
	for (int Y = 0; Y < 3; Y++) {

		for (int i = 0; i < 3; i++) {
			if (i > 0) cout << "  " << (char)186;
			else cout << "   ";
			if (miniBoards[Y][i].checkLittleWin() == 'X') sw::Console::Colors::setConsoleColor(XWinColor, "none");
			else if (miniBoards[Y][i].checkLittleWin() == 'O') sw::Console::Colors::setConsoleColor(OWinColor, "none");
			else if (boardPosXY[0] == i && boardPosXY[1] == Y) sw::Console::Colors::setConsoleColor(selectedColor, "none");

			cout << "   " << miniBoards[Y][i].getVal(0, 0);
			cout << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(1, 0) << " ";
			cout << (char)179;
			cout << " " << miniBoards[Y][i].getVal(2, 0) << " ";
			sw::Console::Colors::setConsoleColor(boardColor, "none");
		}
		cout << endl;
		for (int y = 0; y < 2; y++) {
			cout << "     ";
			for (int x = 0; x < 3; x++) {

				if (miniBoards[Y][x].checkLittleWin() == 'X') sw::Console::Colors::setConsoleColor(XWinColor, "none");
				else if (miniBoards[Y][x].checkLittleWin() == 'O') sw::Console::Colors::setConsoleColor(OWinColor, "none");
				else if (boardPosXY[0] == x && boardPosXY[1] == Y) sw::Console::Colors::setConsoleColor(selectedColor, "none");

				cout << (char)196 << (char)196 << (char)196;
				cout << (char)197;
				cout << (char)196 << (char)196 << (char)196;
				cout << (char)197;
				cout << (char)196 << (char)196 << (char)196;
				sw::Console::Colors::setConsoleColor(boardColor, "none");
				if (x < 2) cout << "  " << (char)186 << "  ";
			}
			cout << endl;
			if (y == 0) {
				for (int i = 0; i < 3; i++) {
					if (i > 0) cout << "  " << (char)186;
					else cout << "   ";

					if (miniBoards[Y][i].checkLittleWin() == 'X') sw::Console::Colors::setConsoleColor(XWinColor, "none");
					else if (miniBoards[Y][i].checkLittleWin() == 'O') sw::Console::Colors::setConsoleColor(OWinColor, "none");
					else if (boardPosXY[0] == i && boardPosXY[1] == Y) sw::Console::Colors::setConsoleColor(selectedColor, "none");

					cout << "   " << miniBoards[Y][i].getVal(0, 1);
					cout << " " << (char)179;
					cout << " " << miniBoards[Y][i].getVal(1, 1);
					cout << " " << (char)179;
					cout << " " << miniBoards[Y][i].getVal(2, 1) << " ";
					sw::Console::Colors::setConsoleColor(boardColor, "none");
				}
				cout << endl;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (i > 0) cout << "  " << (char)186;
			else cout << "   ";

			if (miniBoards[Y][i].checkLittleWin() == 'X') sw::Console::Colors::setConsoleColor(XWinColor, "none");
			else if (miniBoards[Y][i].checkLittleWin() == 'O') sw::Console::Colors::setConsoleColor(OWinColor, "none");
			else if (boardPosXY[0] == i && boardPosXY[1] == Y) sw::Console::Colors::setConsoleColor(selectedColor, "none");

			cout << "   " << miniBoards[Y][i].getVal(0, 2);
			cout << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(1, 2);
			cout << " " << (char)179;
			cout << " " << miniBoards[Y][i].getVal(2, 2) << " ";
			sw::Console::Colors::setConsoleColor(boardColor, "none");
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

	removeGuessOptions();
}
void MainBoard::setGuessOptions()
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (miniBoards[boardPosXY[1]][boardPosXY[0]].getVal(x, y) == ' ')
				miniBoards[boardPosXY[1]][boardPosXY[0]].setVal((char)(y * 3 + x + 49), x, y);
		}
	}
}
void MainBoard::removeGuessOptions()
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (miniBoards[boardPosXY[1]][boardPosXY[0]].getVal(x, y) != 'X' && miniBoards[boardPosXY[1]][boardPosXY[0]].getVal(x, y) != 'O')
				miniBoards[boardPosXY[1]][boardPosXY[0]].setVal(' ', x, y);
		}
	}
}
void MainBoard::showMiniBoardVal(int X, int Y, int x, int y)
{

}

//functions
void MainBoard::setVal(char val, int x1, int y1, int x2, int y2)
{
	miniBoards[y1][x1].setVal(val, x2, y2);
	boardPosXY[0] = x2;
	boardPosXY[1] = y2;

	if (checkLittleWin(boardPosXY[0], boardPosXY[1]) != ' ') chooseSpace = true;
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
char MainBoard::checkLittleWin(int x, int y)
{
	return miniBoards[y][x].checkLittleWin();
}