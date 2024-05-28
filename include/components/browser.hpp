#pragma once

#include "common.hpp"
#include "components/pane.hpp"
#include "fs.hpp"

namespace bff {

class Browser : protected Pane {
public:
  Browser(const path &p, int width, int y, int x, BorderChars border);

  void populate();
  void redraw();
  void move_down();
  void move_up();

  void select(path path);
  path get_selected();

protected:
  static bool compare_entries(const directory_entry a,
                       const directory_entry b);

  const path &m_path;
  int m_sel;
  fs::dir_contents m_directory;
};

} // namespace bff
