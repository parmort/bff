#include <filesystem>
#include <locale>

#include "bff.hpp"

using namespace bff;

int main() {
  setlocale(LC_ALL, "");

  initscr();
  raw();
  keypad(stdscr, true);
  noecho();
  refresh();
  curs_set(0);

  BFF bff = BFF();

  int retcode = bff.run();

  endwin();
  exit(retcode);
}
