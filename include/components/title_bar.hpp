#pragma once

#include "common.hpp"
#include "window.hpp"

namespace bff {

class TitleBar : Window {
public:
  TitleBar(int y, int x);

private:
  string cwd();
};

} // namespace bff
