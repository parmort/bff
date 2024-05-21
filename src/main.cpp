#include <ncurses.h>
#include <locale>

#include "window.hpp"

int main() {
  setlocale(LC_ALL, "");

  initscr();
  raw();
  keypad(stdscr, true);
  noecho();
  refresh();

  Window input_bar = Window(1, COLS, 0, 0);
  input_bar.printf("Hello World");
  input_bar.refresh();

  BorderedWindow sidebar = BorderedWindow(LINES-1, 25, 1, 0);
  sidebar.refresh();

  BorderedWindow browser = BorderedWindow(LINES-1, COLS-25, 1, 25);
  browser.refresh();

  getch();
  endwin();
  return 0;
}
