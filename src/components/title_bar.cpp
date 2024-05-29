#include <format>

#include "colors.hpp"
#include "components/title_bar.hpp"

namespace bff {

TitleBar::TitleBar(const path &p, int y, int x)
    : Window(1, COLS, y, x), m_path(p) {}

void TitleBar::accept(Event e) {
  if (e != Event::Redraw)
    return;

  win_clear();
  build();
  win_refresh();
}

void TitleBar::build() {
  wattron(m_win, A_BOLD | COLOR_PAIR(colors::Directory));

  win_print("%s/", m_path.parent_path().c_str());
  wattroff(m_win, COLOR_PAIR(colors::Directory));

  win_print(m_path.filename());
}

} // namespace bff
