#include "components/pane.hpp"

namespace bff {

Pane::Pane(int height, int width, int y, int x, BorderChars border)
    : Window(height, width, y, x, border) {
  m_content = derwin(m_win, m_height - 2, m_width - 2, 1, 1);
}

Pane::~Pane() {
  win_clear();
  win_refresh();
  delwin(m_content);
}

} // namespace bff
