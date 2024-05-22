#include <curses.h>
#include <locale>
#include <filesystem>

#include "window.hpp"

void get_command(Window *cmd);
void exit_program();

int main() {
  setlocale(LC_ALL, "");

  initscr();
  raw();
  keypad(stdscr, true);
  noecho();
  refresh();

  std::filesystem::path cwd = std::filesystem::current_path();

  Window titlebar = Window(1, COLS, 0, 0);
  titlebar.printf(cwd.string());
  titlebar.refresh();

  BorderedWindow sidebar = BorderedWindow(LINES-2, 26, 1, 0);
  sidebar.refresh();

  Window browser = Window(LINES-2, COLS-25, 1, 25);
  wborder(browser.w, 0, 0, 0, 0, ACS_TTEE, 0, ACS_BTEE, 0);
  browser.refresh();

  Window commandline = Window(1, COLS, LINES-1, 0);
  commandline.refresh();

  char c;
  while ((c = getch()) != (char)KEY_F(1)) {
    switch(c) {
      case ':':
        get_command(&commandline);
        break;
    }
  }

  exit_program();
}

void exit_program() {
  endwin();
  exit(0);
}

void get_command(Window *cmd) {
  std::string buf;
  char c = ':';

  do {
    switch(c) {
      case (char)KEY_BACKSPACE:
        buf.pop_back();
        break;
      default:
        buf.push_back(c);
    }

    wclear(cmd->w);
    mvwprintw(cmd->w, 0, 0, "%s", buf.c_str());
    cmd->refresh();
  } while((c = getch()) != '\n');

  if (buf == ":q") {
    exit_program();
  }

  wclear(cmd->w);
  cmd->refresh();
}
