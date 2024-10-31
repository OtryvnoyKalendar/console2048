#include <locale.h>
#include <ncurses.h>

#include "closecore.hpp"
#include "colors.hpp"

void SetBackgroundColor(int BackgroundColor) {
  init_pair(COLOR_BLACK, COLOR_BLACK, BackgroundColor);
  init_pair(COLOR_GREEN, COLOR_GREEN, BackgroundColor);
  init_pair(COLOR_WHITE, COLOR_WHITE, BackgroundColor);
  init_pair(COLOR_RED, COLOR_RED, BackgroundColor);
  init_pair(COLOR_CYAN, COLOR_CYAN, BackgroundColor);
  init_pair(COLOR_MAGENTA, COLOR_MAGENTA, BackgroundColor);
  init_pair(COLOR_BLUE, COLOR_BLUE, BackgroundColor);
  init_pair(COLOR_YELLOW, COLOR_YELLOW, BackgroundColor);
}

void IncludeColors() {
  if (has_colors()) {
    start_color();
    SetBackgroundColor(COLOR_BLACK);
  } else
    ErrorCloseProgram("терминал не поддерживает цвета");
}

// режим ncurses

void OpenNcursesMode() {
  setlocale(LC_ALL, "");

  initscr();
  savetty();
  nonl();
  cbreak();
  noecho();
  timeout(0);
  leaveok(stdscr, true);
  curs_set(0);

  IncludeColors();
	//setSignals();
}

void CloseNcursesMode() {
  clear();
  refresh();
  resetty();
  curs_set(1);
  endwin();
}

