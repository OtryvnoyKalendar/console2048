#include "colors.hpp"
#include "conscore.hpp"
#include "graphic.hpp"
#include "screen.hpp"
#include "cell.hpp"

void DrawFrame() {
	int rightBorder = console.width-1;
	
	// точки по углам
	PutSymbolToConsole(0, 0, '+', COLOR_RED);
	PutSymbolToConsole(console.height-1, 0, '+', COLOR_RED);
	PutSymbolToConsole(0, rightBorder, '+', COLOR_RED);
	PutSymbolToConsole(console.height-1, rightBorder, '+', COLOR_RED);
	
	// линия сверху
	DrawLine(0, 1, 0, console.width-2, '-', COLOR_WHITE);
	// линия снизу
	DrawLine(console.height-1, 1, console.height-1, console.width-2, '-', COLOR_WHITE);
	
	// линия слева
	DrawLine(1, 0, console.height-2, 0, '|', COLOR_WHITE);
	// линия справа 
	DrawLine(1, rightBorder, console.height-2, rightBorder, '|', COLOR_WHITE);
}

void ShowGraphic() {
	screen.Clear();
	for(int i = 0; i < FIELD_WIDTH*FIELD_HEIGHT; i++)
		cell[0][i].PutToScreen(screen.scr);
	screen.Show();

	DrawFrame();
}

