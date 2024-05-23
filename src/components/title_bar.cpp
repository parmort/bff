#include <filesystem>

#include "components/title_bar.hpp"

namespace bff {

TitleBar::TitleBar(int y, int x) : Window(1, COLS, y, x) {
  win_print(cwd());
  win_refresh();
}

string TitleBar::cwd() { return std::filesystem::current_path().string(); }

} // namespace bff
