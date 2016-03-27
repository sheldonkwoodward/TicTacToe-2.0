#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

namespace sw {
	class Console {
	public:
		class Colors {
		public:
			static void setConsoleColor(int color);
			static void setConsoleColor(string text, string background);
			static int getConsoleColor();
		private:
			static int getColor(string &color, int defaultColor);
		};
		class Cursor {
		public:
			static void resetPos();
			static COORD getPos();
			static void setPos(COORD coord);
			static void clearLine();
			static void backLine();
			static void backLine(int numLines);
			static void clearBelow();
		};
	};
	class Input {
	public:
		static int integer();
		static int integer(int min, int max);
	};
}