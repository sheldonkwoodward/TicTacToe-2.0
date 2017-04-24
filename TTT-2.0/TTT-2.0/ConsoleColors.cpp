#include "ConsoleColors.h"

namespace sw {
	void ConsoleColors::setConsoleColor(register string text, register string background)
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hstdout, getColor(text, 7) + (getColor(background, 0) * 16));
	}

	int ConsoleColors::getColor(string &color, int defaultColor)
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
}