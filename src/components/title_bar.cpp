#include <filesystem>

#include "components/title_bar.hpp"

namespace bff {

TitleBar::TitleBar(const path &p, int y, int x)
    : Window(1, COLS, y, x), m_path(p) {}

void TitleBar::accept(Event e) {
  if (e != Event::Redraw)
    return;

  win_clear();
  win_print(m_path.string());
  win_refresh();
}

string TitleBar::cwd() { return std::filesystem::current_path().string(); }

} // namespace bff
