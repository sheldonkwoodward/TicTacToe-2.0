#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

namespace sw {
	class Console {
	public:
		class Colors {
		public:
			static void setConsoleColor(string text, string background);
		private:
			static int getColor(string &color, int defaultColor);
		};
		class Cursor {
		public:
			static void resetPos();
			static void setPos(COORD coord);
			static void clearLine();
			static void clearBelow();
		};
	};
}