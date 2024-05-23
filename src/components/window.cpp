#include "components/window.hpp"

namespace bff {

const BorderChars NO_BORDER{.ls = ' ',
                            .rs = ' ',
                            .ts = ' ',
                            .bs = ' ',
                            .tl = ' ',
                            .tr = ' ',
                            .bl = ' ',
                            .br = ' '};

Window::Window(int height, int width, int y, int x)
    : Window(height, width, y, x, NO_BORDER) {}

Window::Window(int height, int width, int y, int x, BorderChars border)
    : m_height(height), m_width(width), m_y(y), m_x(x) {
  m_win = newwin(m_height, m_width, m_y, m_x);
  wborder(m_win, border.ls, border.rs, border.ts, border.bs, border.tl,
          border.tr, border.bl, border.br);
  win_refresh();
}

Window::~Window() {
  win_clear();
  win_refresh();
  delwin(m_win);
}

} // namespace bff
