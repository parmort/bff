#pragma once

#include "common.hpp"

namespace bff {

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

  inline int win_refresh() { return wrefresh(m_win); }
  inline int win_clear() { return wclear(m_win); }

  template <typename... Args> inline int win_print(string s, Args... args) {
    return wprintw(m_win, s.c_str(), args...);
  }

  template <typename... Args>
  inline int win_mvprint(int y, int x, string s, Args... args) {
    return mvwprintw(m_win, y, x, s.c_str(), args...);
  }

protected:
  WINDOW *m_win;
  int m_height, m_width;
  int m_y, m_x;
};

} // namespace bff
