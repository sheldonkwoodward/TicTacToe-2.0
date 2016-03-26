//Sheldon Woodward
//Advance Tic Tac Toe
//3-5-16
//Walla Walla University

#include <SFML/Network.hpp>
#include <iostream>
#include <Windows.h>
#include "MainBoard.h"
#include "ComputerPlayer.h"
using namespace std;

void playerTurn(char OX, MainBoard &mainBoard);

int main()
{
	MainBoard mainBoard;
	ComputerPlayer com;
	bool humanTurn = true;

	//show initial board
	mainBoard.showBoard();

	//turns
	while (mainBoard.checkBigWin() == ' ') {
		if (humanTurn == true) {
			playerTurn('X', mainBoard);
			humanTurn = false;
		}
		else if (humanTurn == false) {
			playerTurn('O', mainBoard);
			humanTurn = true;
		}
	}

	return 0;
}

void playerTurn(char OX, MainBoard &mainBoard)
{
	int guess, subX, subY;
	bool inputFailed;

	do {
		//reset inputFailed
		inputFailed = false;

		//get guess
		sw::Console::Cursor::clearLine();
		cout << "Enter your guess: ";
		guess = sw::Input::integer(1, 9);
		guess--;

		//convert to coordinate
		subX = guess % 3;
		subY = guess / 3;

		//check for overlap
		if (mainBoard.checkForVal(subX, subY)) inputFailed = true;

		//reset line if failed
		if (inputFailed) sw::Console::Cursor::backLine();
	} while (inputFailed);

	/*int retry = false;
	do {
		if (retry) {
			sw::Console::Cursor::resetPos();
			mainBoard.showBoard();
			mainBoard.tellBoardPos();
			sw::Console::Cursor::clearLine();
			cout << "That spot is already taken" << endl;
		}
		sw::Console::Cursor::clearLine();
		cout << "Pick a sub section" << endl;
		sw::Console::Cursor::clearBelow();
		cout << "x: ";
		while (subX != 1 && subX != 2 && subX != 3) {
			cin >> subX;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter 1, 2, or 3" << endl << "x: ";
				cin >> subX;
			}
		}
		cout << "y: ";
		while (subY != 1 && subY != 2 && subY != 3) {
			cin >> subY;
			while (cin.fail()) {
				cout << "Enter 1, 2, or 3" << endl << "y: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> subY;
			}
		}

		update sub vals
		subX -= 1;
		subY -= 1;
		retry = true;
	} while (mainBoard.checkForVal(subX, subY) == true);*/

	//set value
	mainBoard.setVal(OX, mainBoard.getBoardX(), mainBoard.getBoardY(), subX, subY);

	//clear screen and show updated board
	sw::Console::Cursor::resetPos();
	mainBoard.showBoard();
}