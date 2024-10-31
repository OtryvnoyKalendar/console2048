#pragma once

void SetConsoleSize(int consoleWidth, int consoleHeight);
void SetConsoleTitle(const char *consoleTitle);

const int FIELD_WIDTH = 4;
const int FIELD_HEIGHT = 4;

const int CELL_WIDTH = 9;
const int CELL_HEIGHT = 5;

const int SCREEN_WIDTH = 47;
const int SCREEN_HEIGHT = 25;

struct Console {
	static const int width = SCREEN_WIDTH;
	static const int height = SCREEN_HEIGHT;
	const char* title;
};

extern Console console;

