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
  KeyHandler(unique_ptr<CommandLine> &cmd_line, unique_ptr<EventHandler> &ev);

  Signal handle_key(char c);

private:
  Signal parse_command(string cmd);

  Signal descend();
  Signal ascend();

  unique_ptr<EventHandler> &m_ev;
  unique_ptr<CommandLine> &m_cmd_line;
};

} // namespace bff
