#pragma once

#include "common.hpp"
#include "components/command_line.hpp"
#include "components/browser.hpp"
#include "components/parent_browser.hpp"
#include "signal.hpp"

namespace bff {

namespace keys {
enum Mappings : char {
  EnterCommandLine = ':',
  MoveSelectionDown = 'j',
  MoveSelectionUp = 'k',
  Descend = 'l',
  Ascend = 'h'
};
}

class KeyHandler {
public:
  KeyHandler(CommandLine *const cmd_line, Browser *const browser,
             ParentBrowser *const parent, path *const p);

  Signal handle_key(char c);

private:
  Signal parse_command(string cmd);

  Signal descend();
  Signal ascend();

  CommandLine *const m_cmd_line;
  Browser *const m_browser;
  ParentBrowser *const m_parent;
  path *const m_path;
};

} // namespace bff
