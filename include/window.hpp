#pragma once

#include <curses.h>
#include <string>

typedef struct m_BorderChars {
  chtype ls = 0;
  chtype rs = 0;
  chtype ts = 0;
  chtype bs = 0;
  chtype tl = 0;
  chtype tr = 0;
  chtype bl = 0;
  chtype br = 0;
} BorderChars;

class Window {
public:
  Window(int height, int width, int y, int x); 
  Window(int height, int width, int y, int x, BorderChars border); 
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
