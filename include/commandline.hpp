#pragma once

#include <string>

#include "window.hpp"

class CommandLine : Window {
public:
  CommandLine(int y, int x);
  std::string get_command();
};
