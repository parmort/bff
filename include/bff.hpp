#pragma once

#include <memory>

#include "common.hpp"
#include "components/browser.hpp"
#include "components/parent_browser.hpp"
#include "components/command_line.hpp"
#include "components/title_bar.hpp"
#include "components/window.hpp"
#include "signal.hpp"
#include "key_handler.hpp"

namespace bff {

class BFF {
public:
  BFF();
  ~BFF();
  int run();

private:
  path m_path;

  ParentBrowser *m_sidebar;
  Browser *m_browser;
  TitleBar *m_title_bar;
  CommandLine *m_command_line;

  KeyHandler *m_key_handler;
};

} // namespace bff
