#pragma once

#include "common.hpp"
#include "window.hpp"
#include "signal.hpp"

namespace bff {

class CommandLine : Window {
public:
  CommandLine(int y, int x);
  string get_command();
};

} // namespace bff
