#pragma once
#include "conscore.hpp"

typedef char ScreenMap[console.height][console.width];
typedef char FieldMap[FIELD_HEIGHT][FIELD_WIDTH];

void InitAll();
void InitGame();

#define SHAPE_ARRAY_NUMBER 5
//extern const int shapeArrayNumber;
extern char* shapeArray[SHAPE_ARRAY_NUMBER];

