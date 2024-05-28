#pragma once

#include "common.hpp"
#include "components/pane.hpp"
#include "fs.hpp"
#include "signal.hpp"

namespace bff {

class Browser : protected Pane {
public:
  Browser(const path &p, int width, int y, int x, BorderChars border);

  void populate();
  void redraw();
  Signal move_down();
  Signal move_up();

  void select(path path);
  directory_entry get_selected();

protected:
  static bool compare_entries(const directory_entry a,
                       const directory_entry b);

  const path &m_path;
  int m_sel;
  fs::dir_contents m_directory;
};

} // namespace bff
