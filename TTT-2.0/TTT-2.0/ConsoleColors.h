#pragma once
#include <Windows.h>
#include <string>
using namespace std;

namespace sw {
	class ConsoleColors {
	public:
		static void setConsoleColor(string text, string background);
	private:
		static int getColor(string &color, int defaultColor);
	};
}