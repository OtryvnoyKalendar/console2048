#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "closecore.hpp"
#include "conscore.hpp"
#include "colors.hpp"
#include "graphic.hpp"
#include "sigcore.hpp"
#include "draw.hpp"
#include "cell.hpp"

#define KEY_ESCAPE ((char)27)

int GetFreeCellCnt() {
	int cnt = 0;
	for(int i = 0; i < FIELD_WIDTH*FIELD_HEIGHT; i++)
		if(cell[0][i].value == 0)
			cnt++;
	return cnt;
}

void PutNewRandNum() {
	srand(time(NULL));
	if(GetFreeCellCnt() == 0)
		return;
	int cnt = 1;
	while(cnt > 0) {
		int x = rand() % FIELD_WIDTH;
		int y = rand() % FIELD_HEIGHT;
		if(cell[y][x].value == 0)
			cell[y][x].value = (rand() % 10 == 0) ? 4 : 2, cnt--;
	}
}

bool MoveValInArray(Cell* valArr[], int arraySize) {
	bool moved = false;
	int lastX = 0;

	for(int i = 1; i < arraySize; i++) {
		if(valArr[i]->value != 0) {
			if(valArr[lastX]->value == 0) {
				moved = true;
				valArr[lastX]->value = valArr[i]->value;
				valArr[i]->value = 0;
			}
			else if(valArr[lastX]->value == valArr[i]->value) {
				moved = true;
				valArr[lastX]->value *= 2;
				valArr[i]->value = 0;
				lastX++;
			}
			else if(valArr[lastX]->value != valArr[i]->value) {
				lastX++;
				if(lastX != i) {
					moved = true;
					valArr[lastX]->value = valArr[i]->value;
					valArr[i]->value = 0;
				}
			}
		}
	}

	return moved;
}

bool CheckLoss() {
	if(GetFreeCellCnt() > 0)
		return false;
	
	// проверка можно ли ещё сделать ход
	for(int i = 0; i < FIELD_WIDTH; i++)
		for(int j = 0; j < FIELD_HEIGHT; j++)
			if((j < FIELD_HEIGHT-1 && cell[j][i].value == cell[j+1][i].value) \
				|| (i < FIELD_WIDTH-1 && cell[j][i].value == cell[j][i+1].value))
				return false;
	return true;
}

void Move(int dy, int dx) {
	bool moved = false;
	if(dx != 0)
		for(int j = 0; j < FIELD_HEIGHT; j++) {
			Cell *valArr[FIELD_WIDTH];
			for(int i = 0; i < FIELD_WIDTH; i++) {
				int x = (dx < 0) ? i : FIELD_WIDTH - 1 - i;
				valArr[i] = &cell[j][x];
			}
			if(MoveValInArray(valArr, FIELD_WIDTH))
				moved = true;
		}
	if(dy != 0)
		for(int i = 0; i < FIELD_WIDTH; i++) {
			Cell* valArr[FIELD_HEIGHT];
			for(int j = 0; j < FIELD_HEIGHT; j++) {
				int y = (dy < 0) ? j : FIELD_HEIGHT - 1 - j;
				valArr[j] = &cell[y][i];
			}
			if(MoveValInArray(valArr, FIELD_HEIGHT))
				moved = true;
		}
	
	if(CheckLoss())
		InitGame();
	else if(moved)
		PutNewRandNum();
}

void GetInput() {
	CheckSignals();

	char input = getch();
	switch(input) {
		case KEY_ESCAPE:
			CloseProgram();
		case 'w':
			Move(-1, 0); break;
		case 's':
			Move(1, 0); break;
		case 'a':
			Move(0, -1); break;
		case 'd':
			Move(0, 1); break;
	};
}

void GameLogic() {
	GetInput();
	ShowGraphic();
	refresh();
}

