#pragma once

#include "common.hpp"
#include "components/window.hpp"

namespace bff {

class Pane : public Window {
public:
  Pane(int height, int width, int y, int x, BorderChars border);
  ~Pane();

  inline int win_refresh() { return wrefresh(m_content); }
  inline int win_clear() { return wclear(m_content); }

  template <typename... Args> inline int win_print(string s, Args... args) {
    return wprintw(m_content, s.c_str(), args...);
  }

  template <typename... Args>
  inline int win_mvprint(int y, int x, string s, Args... args) {
    return mvwprintw(m_content, y, x, s.c_str(), args...);
  }

private:
  WINDOW *m_content;
};

} // namespace bff
