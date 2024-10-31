#pragma once

#include "cell.hpp"

class AnimatedCell : public Cell {
	float ax, ay;
	float dx, dy;
	int animCnt;
	int faceVal;
public:
	AnimatedCell();
	void Animation(POINT toPos);
	bool IsAnim();
	bool IsStat();
	void PutStatToScreen(ScreenMap& scr);
	void Work();
	void PutAnimToScreen(ScreenMap& scr);
};

extern AnimatedCell cell[FIELD_HEIGHT][FIELD_WIDTH];

