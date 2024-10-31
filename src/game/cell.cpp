#include <cstring>
#include <cstdio>

#include "symbols.hpp"
#include "cell.hpp"

bool IsCellInScreen(int y, int x) {
	return (x >= 0 && x < console.width && y >= 0 && y < console.height);
}

void Cell::Init(int y, int x, int _value) {
	value = _value;
	pos = {x, y};
}

Cell::Cell() {
	Init(0, 0, 0);
}

void Cell::PutToScreen(ScreenMap& scr) {
	for(int i = 0; i < CELL_WIDTH; i++)
		for(int j = 0; j < CELL_HEIGHT; j++)
			if(IsCellInScreen(pos.y+j, pos.x+i))
				scr[pos.y+j][pos.x+i] = (i == 0 || i == CELL_WIDTH-1 || 
									j == 0 || j == CELL_HEIGHT-1) ? SYMBOL_CELL : SYMBOL_EMPTY;
	if(value == 0)
		return;
	char buf[6];
	sprintf(buf, "%d", value);
	int len = strlen(buf);
	int posX = (CELL_WIDTH - len) / 2;
	int posY = (CELL_HEIGHT - 1) / 2;
	for(int i = 0; i < len; i++)
		scr[pos.y+posY][pos.x+posX+i] = buf[i];
}

