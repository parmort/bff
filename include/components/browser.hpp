#pragma once

#include "common.hpp"
#include "components/pane.hpp"

namespace bff {

class Browser : Pane {
public:
  Browser(int width, int y, int x, BorderChars border);

  void populate(fs::path path);
  void redraw();

private:
  int m_sel = 0;
  vector<fs::directory_entry>* m_directory;
};

} // namespace bff
