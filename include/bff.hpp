#pragma once

#include <memory>

#include "common.hpp"
#include "components/browser.hpp"
#include "components/parent_browser.hpp"
#include "components/command_line.hpp"
#include "components/title_bar.hpp"
#include "components/window.hpp"

namespace bff {

enum class Signal { Continue, Quit };

class BFF {
public:
  BFF();
  ~BFF();
  int run();

private:
  Signal handle_key(char c);
  Signal parse_command(string cmd);

  path m_path;

  ParentBrowser *m_sidebar;
  Browser *m_browser;
  TitleBar *m_title_bar;
  CommandLine *m_command_line;
};

} // namespace bff
