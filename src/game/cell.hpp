#pragma once

#include "types.hpp"
#include "init.hpp"

class Cell {
public:
	int value;
	POINT pos;

	Cell();
	void Init(int y, int x, int _value);
	void PutToScreen(ScreenMap& scr);
};

