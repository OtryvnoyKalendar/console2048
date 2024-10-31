#include <cstring>

#include "graphic.hpp"
#include "screen.hpp"
#include "symbols.hpp"
#include "conscore.hpp"

void Screen::Clear() {
	memset(scr, SYMBOL_EMPTY, sizeof(scr));
}

Screen::Screen() {
	Clear();
}

void Screen::Show() {
	for(int i = 0; i < console.height; i++)
		for(int j = 0; j < console.width; j++) {
			int color = COLOR_GREEN;
			char symbol = scr[i][j];

			switch(symbol) {
				case SYMBOL_CELL:
					color = COLOR_CELL; break;
				case SYMBOL_EMPTY:
					color = COLOR_EMPTY; break;
			}

			PutSymbolToConsole(i+1, j+1, symbol, color);
		}
}

