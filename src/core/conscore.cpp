#include <iostream>

#include "conscore.hpp" 

void SetConsoleSize(int consoleWidth, int consoleHeight) {
	printf("\e[8;%d;%dt", consoleHeight, consoleWidth);
}

void SetConsoleTitle(const char *consoleTitle) {
	printf("\033]2;%s\007", consoleTitle);
}

