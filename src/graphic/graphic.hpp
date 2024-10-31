#pragma once

void PutSymbolToConsole(int y, int x, char symbol, int color);
void DrawLine(int y1, int x1, int y2, int x2, char symbol, int color);
void DrawCircle(int xCenter, int yCenter, const int radius, char symbol, int color);
void DrawRectangle(int x1, int y1, int x2, int y2, char symbol, int color);
void DrawCircleAspect(int xCenter, int yCenter, const int radius, const float aspectRatio, char symbol, int color);

