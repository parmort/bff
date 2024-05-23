#include <algorithm>
#include <stdio.h>

#include "components/browser.hpp"
#include "fs.hpp"
#include "colors.hpp"

namespace bff {

void color_entry(WINDOW* win, const fs::directory_entry entry);

bool compare_entries(const fs::directory_entry a, const fs::directory_entry b) {
  if (a.is_directory() != b.is_directory())
    return a.is_directory();
  return a.path().filename() < b.path().filename();
}

Browser::Browser(int width, int y, int x, BorderChars border)
    : Pane(LINES - 2, width, y, x, border), m_sel(0) {}

void Browser::populate(fs::path path) {
  m_sel = 0;
  m_directory = FS::dir_contents(path);
  std::sort(m_directory->begin(), m_directory->end(), compare_entries);
}

void Browser::redraw() {
  win_clear();

  int i = 0;
  for (auto const &entry : *m_directory) {
    if (i == m_sel)
      wattron(m_content, A_REVERSE);

    color_entry(m_content, entry);
    win_print(" %-*s", getmaxx(m_content)-1, entry.path().filename().c_str());
    wattrset(m_content, A_NORMAL);

    i++;
  }

  win_refresh();
}

void color_entry(WINDOW* win, fs::directory_entry entry) {
    if (entry.is_directory())
      wattron(win, A_BOLD | COLOR_PAIR(colors::Directory));
}

} // namespace bff
