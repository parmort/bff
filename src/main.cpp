#include <ncurses.h>
#include <locale>
#include <filesystem>

#include "window.hpp"

int main() {
  setlocale(LC_ALL, "");

  initscr();
  cbreak();
  keypad(stdscr, true);
  noecho();
  refresh();

  std::filesystem::path cwd = std::filesystem::current_path();

  Window titlebar = Window(1, COLS, 0, 0);
  titlebar.printf(cwd.string());
  titlebar.refresh();

  BorderedWindow sidebar = BorderedWindow(LINES-2, 25, 1, 0);
  sidebar.refresh();

  BorderedWindow browser = BorderedWindow(LINES-2, COLS-25, 1, 25);
  browser.refresh();

  Window commandline = Window(1, COLS, LINES-1, 0);
  commandline.printf(":");
  commandline.refresh();

  char c;
  while ((c = getch()) != '\n') {
    commandline.printf(std::string{c});
    commandline.refresh();
  }

  endwin();
  return 0;
}
