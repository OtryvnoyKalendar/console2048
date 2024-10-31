#include <cmath>

#include "animcell.hpp"

AnimatedCell::AnimatedCell() : Cell() {
	animCnt = 0;
}

bool AnimatedCell::IsAnim() {
	return animCnt > 0;
}

void AnimatedCell::Animation(POINT toPos) {
	if(IsAnim())
		return;
	faceVal = value;
	animCnt = 20;
	ax = pos.x;
	ay = pos.y;
	dx = (toPos.x - ax) / (float)animCnt;
	dy = (toPos.y - ay) / (float)animCnt;
}

void AnimatedCell::Work() {
	animCnt--;
	ax += dx;
	ay += dy;
}

void AnimatedCell::PutAnimToScreen(ScreenMap& scr) {
	if(IsAnim()) {
		Work();
		if(IsStat())
			return;
		Cell tmpcell;
		tmpcell.Init(lround(ay), lround(ax), faceVal);
		tmpcell.PutToScreen(scr);
	}
}

bool AnimatedCell::IsStat() {
	return dx == 0 && dy == 0;
}

void AnimatedCell::PutStatToScreen(ScreenMap& scr) {
	if(IsAnim()) {
		Cell tmpcell;
		if(IsStat())
			tmpcell.Init(pos.y, pos.x, faceVal);
		else
			tmpcell.Init(pos.y, pos.x, 0);
		tmpcell.PutToScreen(scr);
	}
	else
		PutToScreen(scr);
}

