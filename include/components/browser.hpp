#pragma once

#include "common.hpp"
#include "components/pane.hpp"
#include "fs.hpp"

namespace bff {

class Browser : protected Pane {
public:
  Browser(int width, int y, int x, BorderChars border);

  void populate(fs::path path);
  void redraw();
  void move_down();
  void move_up();
  bool descend(fs::path *path);

  void select(fs::path path);

protected:
  static bool compare_entries(const fs::directory_entry a,
                       const fs::directory_entry b);

  int m_sel = 0;
  vector<fs::directory_entry>* m_directory;
};

} // namespace bff
