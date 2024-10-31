#include <ncurses.h>
#include <cmath>

#include "closecore.hpp"
#include "colors.hpp"
#include "conscore.hpp"

bool IsConsoleCellExists(int y, int x) {
	return (y >= 0 && y < console.height && x >= 0 && x < console.width);
}

void PutSymbolToConsole(int y, int x, char symbol, int color) {
	if(!IsConsoleCellExists(y, x))
		return;
		//ErrorCloseProgram("выход за границы игрового поля");
	
	move(y, x);
	if(color !=	NO_COLOR)
		attron(COLOR_PAIR(color));
	addch(symbol);
}

void DrawLine(int y1, int x1, int y2, int x2, char symbol, int color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = std::max(abs(dx), abs(dy));

	//float xIncrement = static_cast<float>(dx) / steps;
	//float yIncrement = static_cast<float>(dy) / steps;
	float xIncrement = (float)dx / steps;
	float yIncrement = (float)dy / steps;
	
	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++) {
		//PutSymbolToConsole(static_cast<int>(round(y)), static_cast<int>(round(x)), symbol, color);
		PutSymbolToConsole((int)(round(y)), (int)(round(x)), symbol, color);
		
		x += xIncrement;
		y += yIncrement;
	}
}

void DrawRectangle(int x1, int y1, int x2, int y2, char symbol, int color) {
	if(x1 > x2 || y1 > y2)
		return;

	for(int xdraw = x1; xdraw < x2; xdraw++) {
		for(int ydraw = y1; ydraw < y2; ydraw++) {
			PutSymbolToConsole(xdraw, ydraw, symbol, color);
		}
	}
}

void DrawCircleAspect(int xCenter, int yCenter, const int radius, const float aspectRatio, char symbol, int color) {
	int x = radius;
	int y = 0;
	int radiusError = 1 - radius;

	while (x >= y) {
		// Рисуем 8 симметричных точек с учетом соотношения сторон
		PutSymbolToConsole(yCenter + y, static_cast<int>(xCenter + x * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter + y, static_cast<int>(xCenter - x * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter - y, static_cast<int>(xCenter + x * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter - y, static_cast<int>(xCenter - x * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter + x, static_cast<int>(xCenter + y * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter + x, static_cast<int>(xCenter - y * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter - x, static_cast<int>(xCenter + y * aspectRatio), symbol, color);
		PutSymbolToConsole(yCenter - x, static_cast<int>(xCenter - y * aspectRatio), symbol, color);

		y++;

		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}

void DrawCircle(int xCenter, int yCenter, const int radius, char symbol, int color) {
	DrawCircleAspect(xCenter, yCenter, radius, 1.8f, symbol, color);
}

