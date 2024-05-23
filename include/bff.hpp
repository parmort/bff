#pragma once

#include "common.hpp"
#include "components/command_line.hpp"
#include "components/title_bar.hpp"
#include "components/window.hpp"

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
  TitleBar *m_title_bar;
  CommandLine *m_command_line;
};

} // namespace bff
