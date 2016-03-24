//Sheldon Woodward
//Advance Tic Tac Toe
//3-5-16
//Walla Walla University

#include <SFML/Network.hpp>
#include <iostream>
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
	int subX = -1, subY = -1;

	mainBoard.tellBoardPos();

	//sub sections
	int retry = false;
	do {
		if (retry) {
			system("cls");
			mainBoard.showBoard();
			mainBoard.tellBoardPos();
			cout << "That spot is already taken" << endl;
		}

		cout << "Pick a sub section" << endl << "x: ";
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

		//update sub vals
		subX -= 1;
		subY -= 1;
		retry = true;
	} while (mainBoard.checkForVal(subX, subY) == true);

	//set value
	mainBoard.setVal(OX, mainBoard.getBoardX(), mainBoard.getBoardY(), subX, subY);

	//clear screen and show updated board
	system("cls");
	mainBoard.showBoard();
}