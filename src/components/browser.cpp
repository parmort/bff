#include <algorithm>
#include <iostream>

#include "components/browser.hpp"
#include "colors.hpp"

namespace bff {

void color_entry(WINDOW* win, const directory_entry entry);

Browser::Browser(const path &p, int width, int y, int x, BorderChars border)
    : Pane(LINES - 2, width, y, x, border), m_path(p), m_sel(0) {}

Browser::Browser(const path &p, int width, int y, int x)
    : Browser(p, width, y, x, {.tl = ACS_TTEE, .bl = ACS_BTEE}) {}

void Browser::accept(Event e) {
  switch (e) {
  case Event::Populate:
    populate();
    break;
  case Event::Redraw:
    redraw();
    break;
  default:
    break;
  }
}

void Browser::populate() {
  m_sel = 0;
  m_directory = fs::get_dir_contents(m_path);
  std::sort(m_directory.begin(), m_directory.end(), compare_entries);
}

void Browser::select(path path) {
  for (auto it = m_directory.begin(); it != m_directory.end(); ++it) {
    if (it->path().string() != path.string())
      continue;

    m_sel = it - m_directory.begin();
    return;
  }
}

void Browser::redraw() {
  win_clear();

  int i = 0;
  for (auto const &entry : m_directory) {
    if (i == m_sel)
      wattron(m_content, A_REVERSE);

    color_entry(m_content, entry);
    win_print(" %-*s", getmaxx(m_content)-1, entry.path().filename().c_str());
    wattrset(m_content, A_NORMAL);

    i++;
  }

  win_refresh();
}

void color_entry(WINDOW* win, directory_entry entry) {
    if (entry.is_directory())
      wattron(win, A_BOLD | COLOR_PAIR(colors::Directory));
}

bool Browser::compare_entries(const directory_entry a, const directory_entry b) {
  if (a.is_directory() != b.is_directory())
    return a.is_directory();
  return a.path().filename() < b.path().filename();
}

Signal Browser::move_down() {
  if (m_sel + 1 < m_directory.size())
    m_sel++;

  return Signal::Continue;
}

Signal Browser::move_up() {
  if (m_sel - 1 >= 0)
    m_sel--;

  return Signal::Continue;
}

directory_entry Browser::get_selected() {
  return m_directory[m_sel];
}

} // namespace bff
