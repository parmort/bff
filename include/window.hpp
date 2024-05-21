#pragma once

#include <ncurses.h>
#include <string>

class Window {
public:
  Window(int height, int width, int y, int x); 
  ~Window();

  inline int refresh() { return wrefresh(this->w); }

  template<typename... Args> inline int printf(std::string s, Args... args) {
    return wprintw(this->w, s.c_str(), args...);
  }

  WINDOW *w;
private:
  int m_height, m_width;
  int m_y, m_x;
};

class BorderedWindow : public Window {
public:
  BorderedWindow(int height, int width, int y, int x);
  ~BorderedWindow();
};
