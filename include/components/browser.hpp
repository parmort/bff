#pragma once

#include "common.hpp"
#include "components/window.hpp"

namespace bff {

class Browser : Window {
public:
  Browser(int width, int y, int x, BorderChars border);
};

} // namespace bff
