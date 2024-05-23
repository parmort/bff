#include <filesystem>
#include <locale>

#include "bff.hpp"
#include "colors.hpp"

using namespace bff;

int main() {
  setlocale(LC_ALL, "");

  initscr();
  raw();
  keypad(stdscr, true);
  noecho();
  refresh();
  curs_set(0);

  start_color();
  use_default_colors();
  colors::init();

  BFF bff = BFF();

  int retcode = bff.run();

  endwin();
  exit(retcode);
}
