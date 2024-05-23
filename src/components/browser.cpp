#include "components/browser.hpp"

namespace bff {

Browser::Browser(int width, int y, int x, BorderChars border)
    : Pane(LINES - 2, width, y, x, border) {}

void Browser::populate(fs::path path) {
  win_clear();

  for (auto const &dir_entry : fs::directory_iterator{path}) {
    win_print(" %s\n", dir_entry.path().filename().c_str());
  }

  win_refresh();
}

} // namespace bff
