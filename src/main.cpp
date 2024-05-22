#include <curses.h>
#include <locale>
#include <filesystem>

#include "window.hpp"
#include "commandline.hpp"

void parseCommand(std::string cmd);
void exit_program();

int main() {
  setlocale(LC_ALL, "");

  initscr();
  raw();
  keypad(stdscr, true);
  noecho();
  refresh();
  curs_set(0);

  std::filesystem::path cwd = std::filesystem::current_path();

  const BorderChars browserBorder { .tl=ACS_TTEE, .bl=ACS_BTEE };

  Window sidebar = Window(LINES-2, 26, 1, 0, BorderChars());
  Window browser = Window(LINES-2, COLS-25, 1, 25, browserBorder);
  CommandLine commandline = CommandLine(LINES-1, 0);

  Window titlebar = Window(1, COLS, 0, 0);
  titlebar.win_print(cwd.string());
  titlebar.win_refresh();

  char c;
  while (true) {
    c = getch();
    switch(c) {
      case ':':
        std::string cmd = commandline.get_command();
        parseCommand(cmd);
        break;
    }
  }

  exit_program();
}

void exit_program() {
  endwin();
  exit(0);
}

void parseCommand(std::string cmd) {
  if (cmd == ":q") {
    exit_program();
  }
}
