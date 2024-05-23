#include <filesystem>

#include "components/browser.hpp"

namespace bff {

namespace fs = std::filesystem;

Browser::Browser(int width, int y, int x, BorderChars border)
    : Pane(LINES - 2, width, y, x, border) {}

void Browser::update() {
  win_clear();

  auto cwd = fs::current_path();

  for (auto const &dir_entry : fs::directory_iterator{cwd}) {
    win_print(" %s\n", dir_entry.path().filename().c_str());
  }

  win_refresh();
}

} // namespace bff
