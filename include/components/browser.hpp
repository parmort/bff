#pragma once

#include "common.hpp"
#include "components/pane.hpp"

namespace bff {

class Browser : Pane {
public:
  Browser(int width, int y, int x, BorderChars border);
  void populate(fs::path path);
};

} // namespace bff
