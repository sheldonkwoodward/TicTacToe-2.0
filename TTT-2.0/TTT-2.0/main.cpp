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
	int space, bigX, bigY;
	int guess, subX, subY;
	bool inputFailed;

	//clear screen and show updated board
	sw::Console::Cursor::resetPos();
	mainBoard.showBoard();

	do {
		//reset inputFailed
		inputFailed = false;

		if (mainBoard.getChooseSpace()) {
			do {
				sw::Console::Cursor::clearLine();
				cout << "What space would you like to guess in: ";
				space = sw::Input::integer(1, 9);
				space--;

				//convert to coordinate
				bigX = space % 3;
				bigY = space / 3;

				mainBoard.setChooseSpace(false);
				mainBoard.setBoardXY(bigX, bigY);

				sw::Console::Cursor::resetPos();
				mainBoard.showBoard();
			} while (mainBoard.getChooseSpace());
		}


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

	//set value
	mainBoard.setVal(OX, mainBoard.getBoardX(), mainBoard.getBoardY(), subX, subY);
}