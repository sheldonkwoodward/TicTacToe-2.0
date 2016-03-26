#include "SWLib.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void sw::Console::Colors::setConsoleColor(string text, string background)
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdout, getColor(text, 7) + (getColor(background, 0) * 16));
}
int sw::Console::Colors::getColor(string & color, int defaultColor)
{
	if (color == "none" || color == "clear")				return 0;
	else if (color == "darkBlue")							return 1;
	else if (color == "darkGreen")							return 2;
	else if (color == "darkCyan" || color == "darkAqua")	return 3;
	else if (color == "darkRed")							return 4;
	else if (color == "darkPink" || color == "purple")		return 5;
	else if (color == "darkYellow" || color == "gold")		return 6;
	else if (color == "lightGray")							return 7;
	else if (color == "darkGray")							return 8;
	else if (color == "blue")								return 9;
	else if (color == "green")								return 10;
	else if (color == "cyan" || color == "aqua")			return 11;
	else if (color == "red")								return 12;
	else if (color == "pink" || color == "violet")			return 13;
	else if (color == "yellow")								return 14;
	else if (color == "white")								return 15;

	return defaultColor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void sw::Console::Cursor::resetPos()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}
void sw::Console::Cursor::setPos(COORD coord)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sw::Console::Cursor::clearLine()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	cout << "\r";
	for (int i = 0; i < 30; i++) cout << ' ';
	cout << "\r";
}
void sw::Console::Cursor::clearBelow()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//save cursor starting point
	COORD cursor;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		cursor.X = csbi.dwCursorPosition.X;
		cursor.Y = csbi.dwCursorPosition.Y;
	}

	//clear below
	for (int i = 0; i < csbi.srWindow.Bottom - csbi.srWindow.Top - cursor.Y; i++) {
		for (int c = 0; c < csbi.srWindow.Right - csbi.srWindow.Left; c++) cout << ' ';
		cout << endl;
	}

	//reset cursor position
	setPos(cursor);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
