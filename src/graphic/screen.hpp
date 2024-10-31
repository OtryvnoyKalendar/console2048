#pragma once

#include "init.hpp"

class Screen {
public:
	ScreenMap scr;
	Screen();
	void Clear();
	void Show();
};

extern Screen screen;

