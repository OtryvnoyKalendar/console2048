#include "init.hpp"
#include "curscore.hpp"
#include "sigcore.hpp"
#include "screen.hpp"
#include "cell.hpp"
#include "logic.hpp"

Console console = {"Tetrix"};
Screen screen;
Cell cell[FIELD_HEIGHT][FIELD_WIDTH];

//const int shapeArrayNumber = 5;
char* shapeArray[SHAPE_ARRAY_NUMBER] = {
	(char*)".....**..**.....",
	(char*)"....****........",
	(char*)"....***..*......",
	(char*)".....***.*......",
	(char*)".....**.**......",
};

void BeforeCloseProgram() {
	CloseNcursesMode();
}

void InitConsole() {
	SetSignals();
	SetConsoleSize(console.width, console.height);
	SetConsoleTitle(console.title);
	OpenNcursesMode();
}

void InitGame() {
	const int dx = 6;
	const int dy = 3;

	for(int i = 0; i < FIELD_WIDTH; i++)
		for(int j = 0; j < FIELD_HEIGHT; j++)
			cell[j][i].Init(dy+j*(CELL_HEIGHT-1), dx+i*(CELL_WIDTH-1), 0);
	
	for(int i = 0; i < 2; i++)
		PutNewRandNum();
}

void InitAll() {
	InitGame();
	InitConsole();
}

