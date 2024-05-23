#pragma once

#include "commandline.hpp"
#include "common.hpp"
#include "window.hpp"

namespace bff {

enum class Signal { Continue, Quit };

class BFF {
public:
  BFF();
  int run();

private:
  Signal parse_command(string cmd);

  Window *m_sidebar;
  Window *m_browser;
  Window *m_title_bar;
  CommandLine *m_command_line;
};

} // namespace bff
